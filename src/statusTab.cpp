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

#include "statusTab.h"
#include "queueWidget.h"
#include "eewsadmObject.h"

statusTab::statusTab(QWidget *parent,eewsadmObject *eews) : QWidget(parent) {

	setupUi(this) ;

	eewsadm = eews ;

	queueWidget *compileQueue = new queueWidget(this,eewsadm,"compile") ;
	queueWidget *judgeQueue = new queueWidget(this,eewsadm,"judge") ;
	compileLayout->addWidget(compileQueue) ;
	judgeLayout->addWidget(judgeQueue) ;

}
