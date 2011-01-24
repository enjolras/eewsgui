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
#include <QHBoxLayout>
#include "pluginField.h"

pluginField::pluginField(QWidget *parent) : QWidget(parent) {

	setupUi(this) ;

}

void pluginField::setWidgetLayout(QHBoxLayout *newLayout) {

	fieldWidget->setLayout(newLayout) ;

}

void pluginField::setName(QString nameText) {

	fieldName->setText(nameText+":") ;
	fieldNameText = nameText ;

}

void pluginField::restoreValue() {

	setCurrentValue(savedValue) ;

}

std::string pluginField::getNameStdString() {

	return fieldNameText.toStdString() ;

}

void pluginField::fixateValue() {

	setCurrentValue(QVariant(QString::fromStdString(getCurrentValueStdString()))) ;

}
