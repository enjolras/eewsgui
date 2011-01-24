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
#include <QLineEdit>
#include <QVariant>
#include "pluginFieldString.h"

pluginFieldString::pluginFieldString(pluginField *parent) : pluginField(parent) {

	QHBoxLayout *tmpLayout = new QHBoxLayout() ;
	fieldContent = new QLineEdit() ;

	tmpLayout->addWidget(fieldContent) ;
	tmpLayout->addStretch() ;
	tmpLayout->setContentsMargins(0,0,0,0) ;

	setWidgetLayout(tmpLayout) ;

}

void pluginFieldString::setCurrentValue(QVariant currentValue) {

	savedValue = currentValue ;
	fieldContent->setText(currentValue.toString()) ;

}

std::string pluginFieldString::getCurrentValueStdString() {

	return fieldContent->text().toStdString() ;

}
