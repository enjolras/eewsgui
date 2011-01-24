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

#ifndef PREFERENCESWIDGET_H
#define PREFERENCESWIDGET_H

#include "ui_preferencesWidget.h"

class QListWidgetItem ;
class QAbstractButton ;
class eewsadmObject ;

class preferencesWidget : public QWidget, private Ui::preferencesWidget {

	Q_OBJECT

public:
	preferencesWidget(QWidget *parent=0, eewsadmObject *argEews=0) ;

private slots:
	void setPage(QListWidgetItem *argItem, QListWidgetItem *oldItem) ;
	void buttonClicked(QAbstractButton *button) ;

signals:
	void resetClicked() ;
	void applyClicked() ;
	void helpClicked() ;

} ;

#endif // PREFERENCESWIDGET_H
