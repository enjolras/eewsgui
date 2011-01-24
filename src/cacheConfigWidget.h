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

#ifndef CACHECONFIGWIDGET_H
#define CACHECONFIGWIDGET_H

#include "ui_cacheConfigWidget.h"
#include "configWidget.h"

class eewsadmObject ;

class cacheConfigWidget : public configWidget, private Ui::cacheConfigWidget {

	Q_OBJECT

public:
	cacheConfigWidget(eewsadmObject *argEews=0) ;

private:
	eewsadmObject *eewsadm ;
	void loadFields() ;

public slots:
	void applyClicked() ;
	void resetClicked() ;
	void helpClicked() ;

} ;

#endif // CACHECONFIGWIDGET_H
