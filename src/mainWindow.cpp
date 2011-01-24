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
#include <QCloseEvent>
#include <QString>
#include <QCryptographicHash>
#include <QMessageBox>
#include "mainWindow.h"
#include "eewsadmObject.h"
#include "connectDialog.h"
#include "aboutServerDialog.h"
#include "mainWidget.h"
#include "aboutBox.h"

mainWindow::mainWindow(QMainWindow *parent) : QMainWindow(parent) {

	setupUi(this) ;

	eewsadm = new eewsadmObject() ;

	aboutServer = new aboutServerDialog(this,eewsadm) ;
	aboutBox *boxAbout = new aboutBox() ;

	connect(action_Quit,SIGNAL(triggered()),this,SLOT(close())) ;
	connect(action_Server,SIGNAL(triggered()),aboutServer,SLOT(show())) ;
	connect(action_About,SIGNAL(triggered()),boxAbout,SLOT(show())) ;
	connect(action_Disconnect,SIGNAL(triggered()),this,SLOT(closeServer())) ;

	connectServer = new connectDialog(this) ;

	connect(connectServer,SIGNAL(readyToConnect(QString*)),this,SLOT(startConnection(QString*))) ;

	connectServer->show() ;

}

void mainWindow::closeEvent(QCloseEvent *event) {

        QSettings settings("eewsgui","eewsgui") ;
        settings.setValue("General/Geometry",saveGeometry()) ;
        QWidget::closeEvent(event) ;

}

void mainWindow::startConnection(QString *URL) {

	eewsadm->setURL(*URL) ;

	int r ;
	ns2__versionResponse versionResponse ;

	r = eewsadm->version(versionResponse) ;
	if(r != SOAP_OK) {
		QMessageBox::warning(this,tr("Connection error"),tr("Could not connect to server.\nUnknown error.")) ;
	} else {
		connectServer->hide() ;
		aboutServer->loadData() ;
		statusbar->showMessage(tr("Connected to: ") + *URL + " (" + tr("Protocol: ")+QString::number(versionResponse.id)+")") ;
		centralWidget = new mainWidget(this,eewsadm) ;
		connect(centralWidget,SIGNAL(statusBarRelaySignal(QString*)),this,SLOT(updateStatusBar(QString*))) ;
		this->setCentralWidget(centralWidget) ;
	}

}

void mainWindow::updateStatusBar(QString *message) {
	statusbar->showMessage(*message) ;
}

void mainWindow::closeServer() {

	switch(QMessageBox::question(this,tr("Are you sure?"),QString(tr("Are you sure that you\nwant to close this connection?")),QMessageBox::Yes | QMessageBox::No)) {
		case QMessageBox::Yes:
			centralWidget->deleteLater() ;
			connectServer->show() ;
			break ;
		default:
			break ;
	}


}
