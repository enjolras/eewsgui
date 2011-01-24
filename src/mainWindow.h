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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainWindow.h"

class eewsadmObject ;
class QString ;
class connectDialog ;
class aboutServerDialog ;
class mainWidget ;

class mainWindow : public QMainWindow, private Ui::mainWindow {

	Q_OBJECT

public:
	mainWindow(QMainWindow *parent=0) ;

protected:
	eewsadmObject *eewsadm ;

private:
	void closeEvent(QCloseEvent *event) ;
	connectDialog *connectServer ;
	aboutServerDialog *aboutServer ;
	mainWidget *centralWidget ;

public slots:
	void startConnection(QString *URL) ;
	void updateStatusBar(QString *message) ;

private slots:
	void closeServer() ;

} ;

#endif // MAINWINDOW_H
