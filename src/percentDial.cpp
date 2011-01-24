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

#include <QPainter>
#include <QRect>
#include <QColor>
#include <QPoint>
#include "percentDial.h"

percentDial::percentDial(QwtDial *parent, QString label) : QwtDial(parent) {

	this->setScaleArc(45,315) ;
	this->setScale(10,2,10) ;
	this->setRange(0,100) ;

	dialLabel = label ;
}

void percentDial::drawScaleContents(QPainter* painter, const QPoint & center, int radius) const {

	QRect rect(0, 0, 2 * radius, 2 * radius - 10);
	rect.moveCenter(center);

	const QColor color =
	palette().color(QPalette::Text);

	painter->setPen(color);

	const int flags = Qt::AlignBottom | Qt::AlignHCenter;
	painter->drawText(rect, flags, dialLabel);

}
