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
#include "mainWidget.h"
#include "genericTab.h"
#include "eewsadmObject.h"
#include "pluginFieldsTab.h"
#include "statusTab.h"
#include "serverTab.h"
#include "preferencesWidget.h"

mainWidget::mainWidget(QWidget *parent,eewsadmObject *argEews) : QWidget(parent), eewsadm(argEews) {

	setupUi(this) ;

	tabWidget->removeTab(0) ;

	statusTab *tabStatusWidget = new statusTab(this,argEews) ;
	genericTab *tabStatus = new genericTab(this,tabStatusWidget,tr("Queue Status")) ;
	tabWidget->addTab(tabStatus,tr("Queue")) ;

	serverTab *tabServerWidget = new serverTab(this) ;
	genericTab *tabServer = new genericTab(this,tabServerWidget,tr("Server Status")) ;
	tabWidget->addTab(tabServer,tr("Server")) ;

	preferencesWidget *preferencesTab = new preferencesWidget(this,argEews) ;
	genericTab *tabPreferences = new genericTab(this,preferencesTab,tr("Preferences")) ;
	tabWidget->addTab(tabPreferences,tr("Preferences")) ;

	tabWidget->setCurrentIndex(0) ;

}

void mainWidget::statusBarRelaySlot(QString *message) {

	emit(statusBarRelaySignal(message)) ;

}
