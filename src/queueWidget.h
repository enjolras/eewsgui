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

#ifndef QUEUEWIDGET_H
#define QUEUEWIDGET_H

#include "ui_queueWidget.h"

class eewsadmObject ;
class QString ;
class QTimer ;

class queueWidget : public QWidget, private Ui::queueWidget {

	Q_OBJECT

public:
	queueWidget(QWidget *parent=0,eewsadmObject *eews=0,QString queue=0) ;

private:
	eewsadmObject *eewsadm ;
	QString queueName ;
	QTimer *updateTimer ;

private slots:
	void changeDelay(int delay) ;
	void updateQueue() ;

} ;

#endif // QUEUEWIDGET_H
