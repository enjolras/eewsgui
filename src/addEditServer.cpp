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

#include <QMessageBox>
#include <QUrl>
#include "addEditServer.h"

addEditServer::addEditServer(QWidget *parent,QString *oldURL) : QDialog(parent) {

	setupUi(this) ;

	if(oldURL) {
		this->setWindowTitle(tr("Edit Server")) ;
		serverURL->setText(*oldURL) ;
		serverURL->selectAll() ;
	}

	connect(buttonBox,SIGNAL(accepted()),this,SLOT(urlAccepted())) ;
	connect(buttonBox,SIGNAL(rejected()),this,SLOT(deleteLater())) ;

}

void addEditServer::urlAccepted() {

	if(QUrl(serverURL->text(),QUrl::StrictMode).isValid() == TRUE) {
		emit(newURL(serverURL->text())) ;
		this->deleteLater() ;
	} else {
		QMessageBox::warning(this,tr("URL not valid"),tr("The entered URL is not valid.")) ;
		serverURL->selectAll() ;
	}

}
