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
#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QIntValidator>
#include <QComboBox>
#include "pluginFieldsTab.h"
#include "pluginFieldString.h"
#include "pluginFieldInt.h"
#include "pluginFieldBool.h"

pluginFieldsTab::pluginFieldsTab(QDialog *parent,eewsadmObject *eews,ns2__PluginData *argPluginData) : QDialog(parent), pluginData(argPluginData), eewsadm(eews) {

	setupUi(this) ;
	fieldList = new QList<pluginField *>() ;

	connect(startButton,SIGNAL(clicked()),this,SLOT(startPlugin())) ;
	connect(stopButton,SIGNAL(clicked()),this,SLOT(stopPlugin())) ;
	connect(autoloadCombo,SIGNAL(activated(int)),this,SLOT(switchAutoload(int))) ;
	connect(buttonBox,SIGNAL(clicked(QAbstractButton*)),this,SLOT(buttonClicked(QAbstractButton*))) ;

	loadGeneralData() ;
	createFields() ;

}

void pluginFieldsTab::loadGeneralData() {

	descLabel->setText(QString::fromStdString(pluginData->desc)) ;
	autoloadCombo->setCurrentIndex(pluginData->autoload) ;
	if(pluginData->status) {
		startButton->setEnabled(FALSE) ;
		stopButton->setEnabled(TRUE) ;
	} else {
		startButton->setEnabled(TRUE) ;
		stopButton->setEnabled(FALSE) ;
	}

}

void pluginFieldsTab::createFields() {

	ns2__getPluginFieldListResponse pluginFieldListResponse ;
	eewsadm->getPluginFieldList(pluginData->uniqid,pluginFieldListResponse) ;

	QVBoxLayout *mainLayout = new QVBoxLayout(this) ;

	QVBoxLayout *fieldLayout = new QVBoxLayout(this) ;
	QVBoxLayout *fieldNamesLayout = new QVBoxLayout(this) ;
	QVBoxLayout *fieldValuesLayout = new QVBoxLayout(this) ;

	for(int i=0;i<pluginFieldListResponse.pluginFieldList->__size;i++) {

		pluginField *tmpPluginField ;

		if(QString::fromStdString(pluginFieldListResponse.pluginFieldList->__ptr[i]->fieldtype) == QString("str")) {
			tmpPluginField = new pluginFieldString() ;
			std::string tmpValue ;
			eewsadm->getPluginFieldValue(pluginData->uniqid,pluginFieldListResponse.pluginFieldList->__ptr[i]->fieldname,tmpValue) ;
			tmpPluginField->setCurrentValue(QString::fromStdString(tmpValue)) ;
		} else if(QString::fromStdString(pluginFieldListResponse.pluginFieldList->__ptr[i]->fieldtype) == QString("int")) {
			tmpPluginField = new pluginFieldInt() ;
			std::string tmpValue ;
			eewsadm->getPluginFieldValue(pluginData->uniqid,pluginFieldListResponse.pluginFieldList->__ptr[i]->fieldname,tmpValue) ;
			tmpPluginField->setCurrentValue(QString::fromStdString(tmpValue).toInt()) ;
			tmpPluginField->setMax(pluginFieldListResponse.pluginFieldList->__ptr[i]->fieldmax) ;
			tmpPluginField->setMin(pluginFieldListResponse.pluginFieldList->__ptr[i]->fieldmin) ;

		} else if(QString::fromStdString(pluginFieldListResponse.pluginFieldList->__ptr[i]->fieldtype) == QString("bool")) {
			tmpPluginField = new pluginFieldBool() ;
			std::string tmpValue ;
			eewsadm->getPluginFieldValue(pluginData->uniqid,pluginFieldListResponse.pluginFieldList->__ptr[i]->fieldname,tmpValue) ;
			tmpPluginField->setCurrentValue(QString::fromStdString(tmpValue).toInt()) ;
		}

		fieldList->append(tmpPluginField) ;
		tmpPluginField->setName(QString::fromStdString(pluginFieldListResponse.pluginFieldList->__ptr[i]->fieldname)) ;
		fieldLayout->addWidget(tmpPluginField) ;
	}

	mainLayout->addItem(fieldLayout) ;
	mainLayout->addStretch() ;

	fieldsWidget->setLayout(mainLayout) ;

}

void pluginFieldsTab::startPlugin() {

	int status ;
	eewsadm->startPlugin(pluginData->uniqid,status) ;
	emit updatePluginList() ;
	loadGeneralData() ;

}

void pluginFieldsTab::stopPlugin() {

	int status ;
	eewsadm->stopPlugin(pluginData->uniqid,status) ;
	emit updatePluginList() ;
	loadGeneralData() ;

}

void pluginFieldsTab::switchAutoload(int newIndex) {

	int status ;
	eewsadm->setPluginAutoload(pluginData->uniqid,newIndex,status) ;
	emit updatePluginList() ;
	loadGeneralData() ;

}

void pluginFieldsTab::buttonClicked(QAbstractButton *button) {

	pluginField *tmpPluginField ;

	switch(buttonBox->buttonRole(button)) {
		case QDialogButtonBox::ApplyRole:
			foreach(tmpPluginField,*fieldList) {
				int status ;
				eewsadm->setPluginFieldValue(pluginData->uniqid,tmpPluginField->getNameStdString(),tmpPluginField->getCurrentValueStdString(),status) ;
				tmpPluginField->fixateValue() ;
			}
			break ;
		case QDialogButtonBox::ResetRole:
			foreach(tmpPluginField,*fieldList) {
				tmpPluginField->restoreValue() ;
			}
			break ;
		default:
			break ;
	}

}
