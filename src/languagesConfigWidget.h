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

#ifndef LANGUAGESCONFIGWIDGET_H
#define LANGUAGESCONFIGWIDGET_H

#include "ui_languagesConfigWidget.h"
#include "configWidget.h"
#include "eewsadmObject.h"

class languagesConfigWidget : public configWidget, private Ui::languagesConfigWidget {

	Q_OBJECT

public:
	languagesConfigWidget(eewsadmObject *argEews) ;
	bool wantsApplyDiscard() ;

private:
	eewsadmObject *eewsadm ;
	void loadFields() ;

public slots:
	void applyClicked() ;
	void resetClicked() ;
	void helpClicked() ;

private slots:
	void addClicked() ;
	void editClicked() ;
	void removeClicked() ;
	void enableButtons() ;

} ;

Q_DECLARE_METATYPE(ns2__LanguageData*) ;

#endif // LANGUAGESCONFIGWIDGET_H
