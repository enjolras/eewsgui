/***************************************************************************
 *   Copyright (C) 2008 by Miguel Revilla   *
 *   yo@miguelrevilla.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "databaseConfigWidget.h"
#include "eewsadmObject.h"

databaseConfigWidget::databaseConfigWidget(eewsadmObject *argEews) : eewsadm(argEews) {

	setupUi(this) ;
	loadFields() ;

}

void databaseConfigWidget::loadFields() {

	QStringList fieldStrNamesList ;
	QList<QLineEdit*> fieldStrWidgetsList ;

	fieldStrNamesList 	<< "DBHost" << "DBName" << "DBPrefix"
				<< "DBUsername" << "DBPassword" << "DBPort" ;
	fieldStrWidgetsList	<< dbHost << dbName << dbPrefix
				<< dbUsername << dbPassword << dbPort;

	for(int i=0; i<fieldStrNamesList.size(); i++) {

		std::string tmpString ;

		eewsadm->getServerConf(fieldStrNamesList.at(i).toStdString(),tmpString) ;
		fieldStrWidgetsList.at(i)->setText(QString::fromStdString(tmpString)) ;

	}

	std::string tmpString ;

	eewsadm->getServerConf(QString("DBDriver").toStdString(),tmpString) ;

	if(QString::fromStdString(tmpString) == "sqlite") {
		dbDriver->setCurrentIndex(0) ;
	} else if(QString::fromStdString(tmpString) == "mysql") {
		dbDriver->setCurrentIndex(1) ;
	}


}

void databaseConfigWidget::applyClicked() {

	QStringList fieldStrNamesList ;
	QList<QLineEdit*> fieldStrWidgetsList ;

	fieldStrNamesList 	<< "DBHost" << "DBName" << "DBPrefix"
				<< "DBUsername" << "DBPassword" << "DBPort" ;
	fieldStrWidgetsList	<< dbHost << dbName << dbPrefix
				<< dbUsername << dbPassword << dbPort ;

	for(int i=0; i<fieldStrNamesList.size(); i++) {

		struct ns2__setServerConfResponse confResponse ;

		eewsadm->setServerConf(fieldStrNamesList.at(i).toStdString(),
					fieldStrWidgetsList.at(i)->text().toStdString(),
					confResponse) ;
	}

	struct ns2__setServerConfResponse confResponse ;
	eewsadm->setServerConf(QString("DBDriver").toStdString(),
				dbDriver->currentText().toStdString(),
				confResponse) ;

}

void databaseConfigWidget::resetClicked() {

	loadFields() ;
}

void databaseConfigWidget::helpClicked() {

}
