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

#ifndef PLUGINFIELDSTAB_H
#define PLUGINFIELDSTAB_H

#include <QList>
#include "ui_pluginFieldsTab.h"
#include "pluginField.h"
#include "eewsadmObject.h"

class QString ;
class QAbstractButton ;

class pluginFieldsTab : public QDialog, private Ui::pluginFieldsTab {

	Q_OBJECT

public:
	pluginFieldsTab(QDialog *parent=0,eewsadmObject *eews=0,ns2__PluginData *argPluginData=0) ;

private:
	eewsadmObject *eewsadm ;
	ns2__PluginData *pluginData ; ;
	void loadGeneralData() ;
	void createFields() ;
	QList<pluginField *> *fieldList ;

private slots:
	void startPlugin() ;
	void stopPlugin() ;
	void switchAutoload(int index) ;
	void buttonClicked(QAbstractButton *button) ;

signals:
	void updatePluginList() ;

} ;

#endif // PLUGINFIELDSTAB_H
