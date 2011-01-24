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

#include <QHBoxLayout>
#include <QRadioButton>
#include "pluginFieldBool.h"

pluginFieldBool::pluginFieldBool(pluginField *parent) : pluginField(parent) {

	contentYes = new QRadioButton(tr("Yes")) ;
	contentNo = new QRadioButton(tr("No")) ;
	QHBoxLayout *tmpLayout = new QHBoxLayout() ;

	tmpLayout->addWidget(contentYes) ;
	tmpLayout->addWidget(contentNo) ;
	tmpLayout->addStretch() ;
	tmpLayout->setContentsMargins(0,0,0,0) ;
	setWidgetLayout(tmpLayout) ;

}

void pluginFieldBool::setCurrentValue(QVariant currentValue) {

	savedValue = currentValue ;
	if(currentValue.toInt()) contentYes->setChecked(TRUE) ;
	else contentNo->setChecked(TRUE) ;
}

std::string pluginFieldBool::getCurrentValueStdString() {

	return QString::number(contentYes->isChecked()).toStdString() ;

}
