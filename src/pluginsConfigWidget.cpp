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
#include "pluginsConfigWidget.h"
#include "pluginFieldsTab.h"

pluginsConfigWidget::pluginsConfigWidget(eewsadmObject *argEews) : eewsadm(argEews) {

	setupUi(this) ;

	connect(optionsButton,SIGNAL(clicked()),this,SLOT(optionsClicked())) ;


	loadFields() ;

}

void pluginsConfigWidget::optionsClicked() {

	pluginFieldsTab *pluginConfig = new pluginFieldsTab((QDialog*)this,eewsadm,pluginList->selectedItems().at(0)->data(Qt::UserRole).value<ns2__PluginData*>()) ;
	connect(pluginConfig,SIGNAL(updatePluginList()),this,SLOT(resetClicked())) ;

	pluginConfig->show() ;

}

bool pluginsConfigWidget::wantsApplyDiscard() {

	return FALSE ;

}

void pluginsConfigWidget::applyClicked() {

}

void pluginsConfigWidget::resetClicked() {

	loadFields() ;

}

void pluginsConfigWidget::helpClicked() {

}

void pluginsConfigWidget::loadFields() {

	ns2__getPluginListResponse pluginListResponse ;
	eewsadm->getPluginList(pluginListResponse) ;

	pluginList->clearContents() ;
	pluginList->setRowCount(0) ;

	for(int i=0;i<pluginListResponse.pluginList->__size;i++) {

		pluginList->setRowCount(i+1) ;

		// Unique ID
		QTableWidgetItem *idItem = new QTableWidgetItem(QString::fromStdString(pluginListResponse.pluginList->__ptr[i]->uniqid)) ;
		idItem->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter) ;
		idItem->setData(Qt::UserRole,QVariant::fromValue(pluginListResponse.pluginList->__ptr[i])) ;
		pluginList->setItem(i,0,idItem) ;

		// Version
		QTableWidgetItem *versionItem = new QTableWidgetItem(QString::number(pluginListResponse.pluginList->__ptr[i]->version)) ;
		versionItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter) ;
		pluginList->setItem(i,1,versionItem) ;

		// Description
		QTableWidgetItem *descItem = new QTableWidgetItem(QString::fromStdString(pluginListResponse.pluginList->__ptr[i]->desc)) ;
		descItem->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter) ;
		pluginList->setItem(i,2,descItem) ;

	}

	pluginList->horizontalHeader()->setResizeMode(QHeaderView::Fixed) ;
	pluginList->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents) ;
	pluginList->horizontalHeader()->setStretchLastSection(TRUE) ;
	pluginList->resizeRowsToContents() ;

}
