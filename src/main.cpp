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


#include <QApplication>
#include <QTranslator>
#include <QSettings>
#include <QLocale>
#include "mainWindow.h"
#include "eewsadm.nsmap"

int main(int argc, char *argv[])
{
	Q_INIT_RESOURCE(eewsgui) ;
	QApplication app(argc, argv);

        QString locale = QLocale::system().name() ;

	QTranslator qttranslator ;
	qttranslator.load(QString(":/translations/qt_%1.qm").arg(locale)) ;
	app.installTranslator(&qttranslator) ;

	QTranslator translator ;
	translator.load(QString(":/translations/%1.qm").arg(locale)) ;
	app.installTranslator(&translator) ;

	QSettings settings("eewsgui","eewsgui") ;

	mainWindow *mw = new mainWindow() ;
	mw->restoreGeometry(settings.value("General/Geometry").toByteArray()) ;
	mw->show() ;
	return app.exec();
}

