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
#include <QStringList>
#include "languagesConfigWidget.h"
#include "addEditLanguage.h"

languagesConfigWidget::languagesConfigWidget(eewsadmObject *argEews) : eewsadm(argEews) {

	setupUi(this) ;

	connect(addButton,SIGNAL(clicked()),this,SLOT(addClicked())) ;
	connect(editButton,SIGNAL(clicked()),this,SLOT(editClicked())) ;
	connect(removeButton,SIGNAL(clicked()),this,SLOT(removeClicked())) ;
	connect(languageList,SIGNAL(itemSelectionChanged()),this,SLOT(enableButtons())) ;

	editButton->setEnabled(FALSE) ;
	removeButton->setEnabled(FALSE) ;

	languageList->horizontalHeader()->setResizeMode(QHeaderView::Fixed) ;

	loadFields() ;

}

void languagesConfigWidget::enableButtons() {

	editButton->setEnabled(TRUE) ;
	removeButton->setEnabled(TRUE) ;

}

void languagesConfigWidget::loadFields() {

	ns2__getLanguageListResponse languageListResponse ;
	eewsadm->getLanguageList(languageListResponse) ;

	languageList->clearContents() ;

	languageList->setRowCount(languageListResponse.languageList->__size) ;

	for(int i=0;i<languageListResponse.languageList->__size;i++) {

		QTableWidgetItem *idItem = new QTableWidgetItem(QString::fromStdString(languageListResponse.languageList->__ptr[i]->uniqid)) ;
		idItem->setData(Qt::UserRole,QVariant::fromValue(languageListResponse.languageList->__ptr[i])) ;
		languageList->setItem(i,0,idItem) ;

		QTableWidgetItem *descItem = new QTableWidgetItem(QString::fromStdString(languageListResponse.languageList->__ptr[i]->description)) ;
		languageList->setItem(i,1,descItem) ;

	}

	languageList->resizeRowsToContents() ;

}

void languagesConfigWidget::addClicked() {

	addEditLanguage *addLanguage = new addEditLanguage((QDialog*)this,eewsadm) ;
	connect(addLanguage,SIGNAL(languageAdded()),this,SLOT(resetClicked())) ;
	addLanguage->show() ;

}

void languagesConfigWidget::editClicked() {

	addEditLanguage *editLanguage = new addEditLanguage((QDialog*)this,eewsadm,languageList->selectedItems().at(0)->data(Qt::UserRole).value<ns2__LanguageData*>()) ;
	connect(editLanguage,SIGNAL(languageAdded()),this,SLOT(resetClicked())) ;

	editLanguage->show() ;

}

void languagesConfigWidget::removeClicked() {

	QString idToRemove(QString::fromStdString(languageList->selectedItems().at(0)->data(Qt::UserRole).value<ns2__LanguageData*>()->uniqid)) ;

	switch(QMessageBox::question(this,tr("Are you sure?"),QString(tr("Are you sure that you\nwant to remove '%1'?")).arg(idToRemove),QMessageBox::Yes | QMessageBox::No)) {
		case QMessageBox::Yes:
			int status ;
			eewsadm->removeLanguage(idToRemove.toStdString(),status) ;
			loadFields() ;
			break ;
		default:
			break ;
	}

}

void languagesConfigWidget::applyClicked() {

}

void languagesConfigWidget::resetClicked() {

	loadFields() ;

}

void languagesConfigWidget::helpClicked() {

}

bool languagesConfigWidget::wantsApplyDiscard() {

	return FALSE ;

}
