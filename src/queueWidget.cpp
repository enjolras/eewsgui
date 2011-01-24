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

#include <QString>
#include <QStringList>
#include <QTimer>
#include <QTableWidgetItem>
#include "queueWidget.h"
#include "eewsadmObject.h"

queueWidget::queueWidget(QWidget *parent,eewsadmObject *eews,QString queue) : QWidget(parent) {

	setupUi(this) ;

	upButton->setText("") ;
	upButton->setIcon(style()->standardIcon(QStyle::SP_ArrowUp)) ;
	downButton->setText("") ;
	downButton->setIcon(style()->standardIcon(QStyle::SP_ArrowDown)) ;
	pauseButton->setText("") ;
	pauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause)) ;
	stopButton->setText("") ;
	stopButton->setIcon(style()->standardIcon(QStyle::SP_MediaStop)) ;

	eewsadm = eews ;
	queueName = queue ;

	updateTimer = new QTimer() ;

	updateQueue() ;

	connect(updateButton,SIGNAL(clicked()),this,SLOT(updateQueue())) ;
	connect(updateTimer,SIGNAL(timeout()),this,SLOT(updateQueue())) ;
	connect(updateTime,SIGNAL(valueChanged(int)),this,SLOT(changeDelay(int))) ;

	changeDelay(updateTime->value()) ;

}

void queueWidget::updateQueue() {

	queueTable->clear() ;

	queueTable->setColumnCount(5) ;

	QStringList labels ;
	labels << tr("Ticket") << tr("Priority") << tr("Language") << tr("Plugin") << tr("Timestamp") << tr("Status") ;
	queueTable->setHorizontalHeaderLabels(labels) ;

	ns2__getQueueResponse response ;

	eewsadm->getQueue(queueName.toStdString(),response) ;

	queueTable->setRowCount(response.queueList->__size) ;

	for(int i=0;i<response.queueList->__size;i++) {
		QTableWidgetItem *tmpSubmissionItem = new QTableWidgetItem(QString::fromStdString(response.queueList->__ptr[i]->ticket)) ;
		queueTable->setItem(i,0,tmpSubmissionItem) ;

		QTableWidgetItem *tmpPriorityItem = new QTableWidgetItem(QString::number(response.queueList->__ptr[i]->priority)) ;
		queueTable->setItem(i,1,tmpPriorityItem) ;

		QTableWidgetItem *tmpLanguageItem = new QTableWidgetItem(QString::fromStdString(response.queueList->__ptr[i]->language)) ;
		queueTable->setItem(i,2,tmpLanguageItem) ;

		QTableWidgetItem *tmpPluginItem = new QTableWidgetItem(QString::fromStdString(response.queueList->__ptr[i]->plugin)) ;
		queueTable->setItem(i,3,tmpPluginItem) ;

		QTableWidgetItem *tmpTimestampItem = new QTableWidgetItem(QString::number(response.queueList->__ptr[i]->timestamp)) ;
		queueTable->setItem(i,4,tmpTimestampItem) ;

	}

	queueTable->resizeRowsToContents() ;
}

void queueWidget::changeDelay(int delay) {

	if(delay) {
		if(!updateTimer->isActive()) updateTimer->start() ;
		updateTimer->setInterval(delay * 1000) ;
	} else {
		updateTimer->stop() ;
	}

}
