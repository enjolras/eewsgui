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

#include <QSettings>
#include <QList>
#include <QListWidget>
#include <QListWidgetItem>
#include <QMessageBox>
#include "serversDialog.h"
#include "addEditServer.h"

serversDialog::serversDialog(QWidget *parent) : QDialog(parent) {

	setupUi(this) ;

	connect(buttonBox,SIGNAL(rejected()),this,SLOT(deleteLater())) ;
	connect(buttonBox,SIGNAL(accepted()),this,SLOT(acceptList())) ;
	connect(addButton,SIGNAL(clicked()),this,SLOT(addServer())) ;
	connect(editButton,SIGNAL(clicked()),this,SLOT(editServer())) ;
	connect(removeButton,SIGNAL(clicked()),this,SLOT(removeServer())) ;
	connect(serverList,SIGNAL(itemSelectionChanged()),this,SLOT(rowChanged())) ;

	updateServerList() ;

}

void serversDialog::updateServerList() {

	QSettings settings("eewsgui","eewsgui") ;

	int size = settings.beginReadArray("General/Servers") ;

	for(int i=0;i<size;i++) {
		settings.setArrayIndex(i) ;
		serverList->addItem(settings.value("URL").toString()) ;
	}

	settings.endArray() ;

}

void serversDialog::addServer() {

	addEditServer *addServer = new addEditServer(this) ;
	connect(addServer,SIGNAL(newURL(QString)),this,SLOT(addServerURL(QString))) ;
	addServer->show() ;

}

void serversDialog::addServerURL(QString newURL) {

	serverList->addItem(newURL) ;

}

void serversDialog::editServer() {

	addEditServer *editServer = new addEditServer(this,&serverList->selectedItems().at(0)->text()) ;
	connect(editServer,SIGNAL(newURL(QString)),this,SLOT(editServerURL(QString))) ;
	editServer->show() ;

}

void serversDialog::editServerURL(QString newURL) {

	serverList->selectedItems().at(0)->setText(newURL) ;

}

void serversDialog::acceptList() {

	QSettings settings("eewsgui","eewsgui") ;

	settings.beginWriteArray("General/Servers") ;

	for(int i=0;i<serverList->count();i++) {
		settings.setArrayIndex(i) ;
		settings.setValue("URL",serverList->item(i)->text()) ;
	}
	settings.endArray() ;

	emit serversUpdated() ;

	this->deleteLater() ;
}

void serversDialog::rowChanged() {

	if(serverList->selectedItems().count()) {
		editButton->setEnabled(TRUE) ;
		removeButton->setEnabled(TRUE) ;
	} else {
		editButton->setEnabled(FALSE) ;
		removeButton->setEnabled(FALSE) ;
	}

}

void serversDialog::removeServer() {

	if(QMessageBox::question(this,tr("Remove server"),tr("Are you sure that you want to\nremove the server '%1'?").arg(serverList->selectedItems().at(0)->text()),QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes) {
		serverList->takeItem(serverList->row(serverList->selectedItems().at(0))) ;
		serverList->setCurrentItem(0) ;
	}

}
