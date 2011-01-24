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

#ifndef PLUGINFIELD_H
#define PLUGINFIELD_H

#include "ui_pluginField.h"

class QHBoxLayout ;
class QVariant ;
class QString ;

class pluginField : public QWidget, private Ui::pluginField {

	Q_OBJECT

public:
	pluginField(QWidget *parent=0) ;
	void setName(QString nameText) ;
	std::string getNameStdString() ;
	void restoreValue() ;
	void fixateValue() ;
	virtual void setCurrentValue(QVariant currentValue) = 0 ;
	virtual std::string getCurrentValueStdString() = 0 ;
	virtual void setMax(int maxValue) { maxValue = maxValue ; } ;
	virtual void setMin(int minValue) { minValue = minValue ; } ;

protected:
	void setWidgetLayout(QHBoxLayout *newLayout=0) ;
	QVariant savedValue ;
	QString fieldNameText ;

} ;

#endif // PLUGINFIELD_H
