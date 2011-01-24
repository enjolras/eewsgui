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

#include <QSpinBox>
#include <QHBoxLayout>
#include "pluginFieldInt.h"

pluginFieldInt::pluginFieldInt(pluginField *parent) : pluginField(parent) {

	fieldContent = new QSpinBox() ;
	QHBoxLayout *tmpLayout = new QHBoxLayout() ;

	tmpLayout->addWidget(fieldContent) ;
	tmpLayout->addStretch() ;
	tmpLayout->setContentsMargins(0,0,0,0) ;

	setWidgetLayout(tmpLayout) ;

}

void pluginFieldInt::setCurrentValue(QVariant currentValue) {

	savedValue = currentValue ;
	fieldContent->setValue(currentValue.toInt()) ;

}

void pluginFieldInt::setMax(int maxValue) {

	fieldContent->setMaximum(maxValue) ;

}

void pluginFieldInt::setMin(int minValue) {

	fieldContent->setMinimum(minValue) ;

}

std::string pluginFieldInt::getCurrentValueStdString() {

	return QString::number(fieldContent->value()).toStdString() ;

}
