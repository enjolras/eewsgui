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
#include "addEditLanguage.h"

addEditLanguage::addEditLanguage(QDialog *parent,eewsadmObject *eews,ns2__LanguageData *editLang) : QDialog(parent) {

	setupUi(this) ;

	eewsadm = eews ;

	if(editLang) {
		this->setWindowTitle(tr("Edit Language")) ;
		addButton->setText(tr("Edit")) ;
		langID->setEnabled(FALSE) ;

		langID->setText(QString::fromStdString(editLang->uniqid)) ;
		langName->setText(QString::fromStdString(editLang->name)) ;
		langVersion->setText(QString::fromStdString(editLang->version)) ;
		langDesc->setText(QString::fromStdString(editLang->description)) ;
		langCompile->setText(QString::fromStdString(editLang->compile)) ;
		langLink->setText(QString::fromStdString(editLang->link)) ;
		langRun->setText(QString::fromStdString(editLang->run)) ;
		langSrcExt->setText(QString::fromStdString(editLang->srcext)) ;
		langObjExt->setText(QString::fromStdString(editLang->objext)) ;
		langExeExt->setText(QString::fromStdString(editLang->exeext)) ;
		langCalCode->setPlainText(QString::fromStdString(editLang->calcode)) ;
		langMemOffset->setText(QString::number(editLang->memoffset)) ;

		connect(addButton,SIGNAL(clicked()),this,SLOT(commitEdit())) ;
		connect(calibrateButton,SIGNAL(clicked()),this,SLOT(calibrateLang())) ;
		calibrateButton->setEnabled(TRUE) ;
	} else {
		connect(addButton,SIGNAL(clicked()),this,SLOT(commitAdd())) ;
		calibrateButton->setEnabled(FALSE) ;
	}

	connect(cancelButton,SIGNAL(clicked()),this,SLOT(deleteLater())) ;

}

void addEditLanguage::commitEdit() {

	int status = 0 ;

	eewsadm->removeLanguage(langID->text().toStdString(),status) ;

	ns2__LanguageData *langData = new ns2__LanguageData() ;
	langData->uniqid = langID->text().toStdString() ;
	langData->name = langName->text().toStdString() ;
	langData->version = langVersion->text().toStdString() ;
	langData->description = langDesc->text().toStdString() ;
	langData->compile = langCompile->text().toStdString() ;
	langData->link = langLink->text().toStdString() ;
	langData->run = langRun->text().toStdString() ;
	langData->srcext = langSrcExt->text().toStdString() ;
	langData->objext = langObjExt->text().toStdString() ;
	langData->exeext = langExeExt->text().toStdString() ;
	langData->calcode = langCalCode->toPlainText().toStdString() ;

	eewsadm->addLanguage(langData,status) ;

	emit(languageAdded()) ;

	this->deleteLater() ;

}

void addEditLanguage::commitAdd() {

	ns2__LanguageData *langData = new ns2__LanguageData() ;
	langData->uniqid = langID->text().toStdString() ;
	langData->name = langName->text().toStdString() ;
	langData->version = langVersion->text().toStdString() ;
	langData->description = langDesc->text().toStdString() ;
	langData->compile = langCompile->text().toStdString() ;
	langData->link = langLink->text().toStdString() ;
	langData->run = langRun->text().toStdString() ;
	langData->srcext = langSrcExt->text().toStdString() ;
	langData->objext = langObjExt->text().toStdString() ;
	langData->exeext = langExeExt->text().toStdString() ;
	langData->calcode = langCalCode->toPlainText().toStdString() ;

	int status = 0;

	eewsadm->addLanguage(langData,status) ;

	emit(languageAdded()) ;

	this->deleteLater() ;

}

void addEditLanguage::calibrateLang() {

	int status=0 ;
	eewsadm->calibrateLanguage(langID->text().toStdString(),status) ;

}
