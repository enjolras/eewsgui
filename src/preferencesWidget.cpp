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

#include <QListWidgetItem>
#include <QIcon>
#include <QVariant>
#include <QPushButton>
#include "preferencesWidget.h"
#include "serverConfigWidget.h"
#include "databaseConfigWidget.h"
#include "cacheConfigWidget.h"
#include "languagesConfigWidget.h"
#include "pluginsConfigWidget.h"
#include "configWidget.h"

preferencesWidget::preferencesWidget(QWidget *parent,eewsadmObject *argEews) : QWidget(parent) {

	setupUi(this) ;

	listWidget->setGridSize(QSize(listWidget->contentsRect().width(),72)) ;

	connect(buttonBox,SIGNAL(clicked(QAbstractButton*)),this,SLOT(buttonClicked(QAbstractButton*))) ;

	QListWidgetItem *serverItem = new QListWidgetItem(QIcon(":/images/icon-server.png"),tr("Server")) ;
	serverItem->setTextAlignment(Qt::AlignVCenter | Qt::AlignLeft) ;
	serverConfigWidget *serverWidget = new serverConfigWidget(argEews) ;
	QVariant serverVariant = QVariant::fromValue((QWidget*)serverWidget) ;
	serverItem->setData(Qt::UserRole, serverVariant) ;
	serverItem->setSizeHint(QSize(256,72)) ;
	listWidget->addItem(serverItem) ;

	QListWidgetItem *databaseItem = new QListWidgetItem(QIcon(":/images/icon-database.png"),tr("Database")) ;
	databaseItem->setTextAlignment(Qt::AlignVCenter | Qt::AlignLeft) ;
	databaseConfigWidget *databaseWidget = new databaseConfigWidget(argEews) ;
	QVariant databaseVariant = QVariant::fromValue((QWidget*)databaseWidget) ;
	databaseItem->setData(Qt::UserRole, databaseVariant) ;
	databaseItem->setSizeHint(QSize(256,72)) ;
	listWidget->addItem(databaseItem) ;

	QListWidgetItem *cacheItem = new QListWidgetItem(QIcon(":/images/icon-cache.png"),tr("LO Cache")) ;
	cacheItem->setTextAlignment(Qt::AlignVCenter | Qt::AlignLeft) ;
	cacheConfigWidget *cacheWidget = new cacheConfigWidget(argEews) ;
	QVariant cacheVariant = QVariant::fromValue((QWidget*)cacheWidget) ;
	cacheItem->setData(Qt::UserRole, cacheVariant) ;
	cacheItem->setSizeHint(QSize(256,72)) ;
	listWidget->addItem(cacheItem) ;

	QListWidgetItem *languagesItem = new QListWidgetItem(QIcon(":/images/icon-languages.png"),tr("Languages")) ;
	languagesItem->setTextAlignment(Qt::AlignVCenter | Qt::AlignLeft) ;
	languagesConfigWidget *languagesWidget = new languagesConfigWidget(argEews) ;
	QVariant languagesVariant = QVariant::fromValue((QWidget*)languagesWidget) ;
	languagesItem->setData(Qt::UserRole, languagesVariant) ;
	languagesItem->setSizeHint(QSize(256,72)) ;
	listWidget->addItem(languagesItem) ;

	QListWidgetItem *pluginsItem = new QListWidgetItem(QIcon(":/images/icon-plugins.png"),tr("Plugins")) ;
	pluginsItem->setTextAlignment(Qt::AlignVCenter | Qt::AlignLeft) ;
	pluginsConfigWidget *pluginsWidget = new pluginsConfigWidget(argEews) ;
	QVariant pluginsVariant = QVariant::fromValue((QWidget*)pluginsWidget) ;
	pluginsItem->setData(Qt::UserRole, pluginsVariant) ;
	pluginsItem->setSizeHint(QSize(256,72)) ;
	listWidget->addItem(pluginsItem) ;

	mainLayout->addWidget(serverWidget) ;
	connect(this,SIGNAL(applyClicked()),serverWidget,SLOT(applyClicked())) ;
	connect(this,SIGNAL(resetClicked()),serverWidget,SLOT(resetClicked())) ;
	if(serverWidget->wantsHelp()) {
		connect(this,SIGNAL(helpClicked()),serverWidget,SLOT(helpClicked())) ;
		buttonBox->button(QDialogButtonBox::Help)->setDisabled(FALSE) ;
	} else {
		buttonBox->button(QDialogButtonBox::Help)->setDisabled(TRUE) ;
	}
	listWidget->setCurrentItem(serverItem) ;

	databaseWidget->hide() ;
	mainLayout->addWidget(databaseWidget) ;

	cacheWidget->hide() ;
	mainLayout->addWidget(cacheWidget) ;

	languagesWidget->hide() ;
	mainLayout->addWidget(languagesWidget) ;

	pluginsWidget->hide() ;
	mainLayout->addWidget(pluginsWidget) ;

	connect(listWidget,SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
		this,SLOT(setPage(QListWidgetItem*,QListWidgetItem*))) ;

}

void preferencesWidget::setPage(QListWidgetItem *argItem, QListWidgetItem *oldItem) {

	disconnect(SIGNAL(applyClicked())) ;
	disconnect(SIGNAL(resetClicked())) ;

	if(((configWidget*)oldItem->data(Qt::UserRole).value<QWidget*>())->wantsHelp()) {
		disconnect(SIGNAL(helpClicked())) ;
	}

	oldItem->data(Qt::UserRole).value<QWidget*>()->hide() ;


	if(((configWidget*)argItem->data(Qt::UserRole).value<QWidget*>())->wantsHelp()) {
		connect(this,SIGNAL(helpClicked()),argItem->data(Qt::UserRole).value<QWidget*>(),SLOT(helpClicked())) ;
		buttonBox->button(QDialogButtonBox::Help)->setDisabled(FALSE) ;
	} else {
		buttonBox->button(QDialogButtonBox::Help)->setDisabled(TRUE) ;
	}

	if(((configWidget*)argItem->data(Qt::UserRole).value<QWidget*>())->wantsApplyDiscard()) {
		connect(this,SIGNAL(applyClicked()),argItem->data(Qt::UserRole).value<QWidget*>(),SLOT(applyClicked())) ;
		connect(this,SIGNAL(resetClicked()),argItem->data(Qt::UserRole).value<QWidget*>(),SLOT(resetClicked())) ;
		buttonBox->button(QDialogButtonBox::Apply)->setDisabled(FALSE) ;
		buttonBox->button(QDialogButtonBox::Discard)->setDisabled(FALSE) ;
	} else {
		buttonBox->button(QDialogButtonBox::Apply)->setDisabled(TRUE) ;
		buttonBox->button(QDialogButtonBox::Discard)->setDisabled(TRUE) ;
	}

	argItem->data(Qt::UserRole).value<QWidget*>()->show() ;

}

void preferencesWidget::buttonClicked(QAbstractButton *button) {

	if(buttonBox->buttonRole(button) == QDialogButtonBox::ApplyRole) {
		emit applyClicked() ;
	} else if(buttonBox->buttonRole(button) == QDialogButtonBox::DestructiveRole) {
		emit resetClicked() ;
	} else if(buttonBox->buttonRole(button) == QDialogButtonBox::HelpRole) {
		emit helpClicked() ;
	}
}
