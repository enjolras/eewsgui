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

#include <QStringList>
#include <QList>
#include "serverConfigWidget.h"
#include "eewsadmObject.h"

serverConfigWidget::serverConfigWidget(eewsadmObject *argEews) : eewsadm(argEews) {

	setupUi(this) ;
	loadFields() ;

}

void serverConfigWidget::loadFields() {

	QStringList fieldStrNamesList ;
	QList<QLineEdit*> fieldStrWidgetsList ;
	QStringList fieldIntNamesList ;
	QList<QSpinBox*> fieldIntWidgetsList ;

	fieldStrNamesList 	<< "PluginDir" << "SvcPort" << "AdmPort"
				<< "AdminEmail" << "Owner" << "WorkDir" ;
	fieldStrWidgetsList	<< pluginDir << servicesPort << adminPort
				<< adminEmail << owner << workDir;

	fieldIntNamesList	<< "CQSlots" << "JQSlots" ;
	fieldIntWidgetsList	<< cqSlots << jqSlots ;


	for(int i=0; i<fieldStrNamesList.size(); i++) {

		std::string tmpString ;

		eewsadm->getServerConf(fieldStrNamesList.at(i).toStdString(),tmpString) ;
		fieldStrWidgetsList.at(i)->setText(QString::fromStdString(tmpString)) ;

	}

	for(int i=0; i<fieldIntNamesList.size(); i++) {

		std::string tmpString ;

		eewsadm->getServerConf(fieldIntNamesList.at(i).toStdString(),tmpString) ;
		fieldIntWidgetsList.at(i)->setValue(QString::fromStdString(tmpString).toInt()) ;

	}

}

void serverConfigWidget::applyClicked() {

	QStringList fieldStrNamesList ;
	QList<QLineEdit*> fieldStrWidgetsList ;
	QStringList fieldIntNamesList ;
	QList<QSpinBox*> fieldIntWidgetsList ;

	fieldStrNamesList 	<< "PluginDir" << "SvcPort" << "AdmPort"
				<< "AdminEmail" << "Owner" << "WorkDir" ;
	fieldStrWidgetsList	<< pluginDir << servicesPort << adminPort
				<< adminEmail << owner << workDir;

	fieldIntNamesList	<< "CQSlots" << "JQSlots" ;
	fieldIntWidgetsList	<< cqSlots << jqSlots ;


	for(int i=0; i<fieldStrNamesList.size(); i++) {

		struct ns2__setServerConfResponse confResponse ;

		eewsadm->setServerConf(fieldStrNamesList.at(i).toStdString(),
					fieldStrWidgetsList.at(i)->text().toStdString(),
					confResponse) ;
	}

	for(int i=0; i<fieldIntNamesList.size(); i++) {

		struct ns2__setServerConfResponse confResponse ;

		eewsadm->setServerConf(fieldIntNamesList.at(i).toStdString(),
					QString::number(fieldIntWidgetsList.at(i)->value()).toStdString(),
					confResponse) ;
	}

}

void serverConfigWidget::resetClicked() {

	loadFields() ;

}

void serverConfigWidget::helpClicked() {

}
