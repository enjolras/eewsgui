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

#ifndef SERVERSDIALOG_H
#define SERVERSDIALOG_H

#include "ui_serversDialog.h"

class QListWidgetItem ;

class serversDialog : public QDialog, private Ui::serversDialog {

	Q_OBJECT

public:
	serversDialog(QWidget *parent=0) ;

private:
	void updateServerList() ;

private slots:
	void acceptList() ;
	void addServer() ;
	void addServerURL(QString newURL) ;
	void editServer() ;
	void editServerURL(QString newURL) ;
	void rowChanged() ;
	void removeServer() ;

signals:
	void serversUpdated() ;

} ;

#endif // SERVERSDIALOG_H
