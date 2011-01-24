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

#ifndef PERCENTDIAL_H
#define PERCENTDIAL_H

#include <qwt_dial.h>
#include <QString>

class QPainter ;

class percentDial : public QwtDial {

	Q_OBJECT

public:
	percentDial(QwtDial *parent=0, QString label="") ;

protected:
	virtual void drawScaleContents(QPainter* painter, const QPoint & center, int radius) const ;

private:
	QString dialLabel ;

} ;

#endif // PERCENTDIAL_H
