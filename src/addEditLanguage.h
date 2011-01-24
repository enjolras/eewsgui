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

#ifndef ADDEDITLANGUAGE_H
#define ADDEDITLANGUAGE_H

#include "ui_addEditLanguage.h"
#include "eewsadmObject.h"

class addEditLanguage : public QDialog, private Ui::addEditLanguage {

	Q_OBJECT

public:
	addEditLanguage(QDialog *parent=0,eewsadmObject *eews=0,ns2__LanguageData *editLang=0) ;

private:
	eewsadmObject *eewsadm ;

private slots:
	void commitEdit() ;
	void commitAdd() ;
	void calibrateLang() ;

signals:
	void languageAdded() ;

} ;

#endif // ADDEDITLANGUAGE_H
