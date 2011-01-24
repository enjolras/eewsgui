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
#include "connectDialog.h"
#include "serversDialog.h"

connectDialog::connectDialog(QWidget *parent) : QDialog(parent) {

	setupUi(this) ;

	connect(serversButton,SIGNAL(clicked()),this,SLOT(serversClicked())) ;
	connect(connectButton,SIGNAL(clicked()),this,SLOT(connectClicked())) ;
	connect(quitButton,SIGNAL(clicked()),qApp,SLOT(quit())) ;

	updateList() ;

}

void connectDialog::connectClicked() {

	URL = new QString(serverURL->currentText()) ;
	emit readyToConnect(URL) ;

}

void connectDialog::serversClicked() {

	serversDialog *servers = new serversDialog(this) ;
	connect(servers,SIGNAL(serversUpdated()),this,SLOT(updateList())) ;
	servers->show() ;

}

void connectDialog::updateList() {

	serverURL->clear() ;
	QSettings settings("eewsgui","eewsgui") ;

	int size = settings.beginReadArray("General/Servers") ;

	for(int i=0;i<size;i++) {
		settings.setArrayIndex(i) ;
		serverURL->addItem(settings.value("URL").toString()) ;
	}

	settings.endArray() ;

}
