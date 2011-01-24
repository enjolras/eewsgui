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

#include "serverTab.h"
#include "percentDial.h"

#define DIALSIZE 150

serverTab::serverTab(QWidget *parent) : QWidget(parent) {

	setupUi(this) ;

/*	percentDial *systemCPUDial = new percentDial(0, tr("System CPU")) ;
	systemCPUDial->setMaximumWidth(DIALSIZE) ;
	systemCPUDial->setMaximumHeight(DIALSIZE) ;
	systemCPULayout->addWidget(systemCPUDial) ;

	percentDial *userCPUDial = new percentDial(0, tr("User CPU")) ;
	userCPUDial->setMaximumWidth(DIALSIZE) ;
	userCPUDial->setMaximumHeight(DIALSIZE) ;
	userCPULayout->addWidget(userCPUDial) ;

	percentDial *waitingCPUDial = new percentDial(0, tr("Waiting CPU")) ;
	waitingCPUDial->setMaximumWidth(DIALSIZE) ;
	waitingCPUDial->setMaximumHeight(DIALSIZE) ;
	waitingCPULayout->addWidget(waitingCPUDial) ;*/

}
