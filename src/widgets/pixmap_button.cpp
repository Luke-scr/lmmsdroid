#ifndef SINGLE_SOURCE_COMPILE

/*
 * pixmap_button.cpp - implementation of pixmap-button (often used as "themed"
 *                     checkboxes/radiobuttons etc)
 *
 * Copyright (c) 2004-2006 Tobias Doerffel <tobydox/at/users.sourceforge.net>
 * 
 * This file is part of Linux MultiMedia Studio - http://lmms.sourceforge.net
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */
 

#include "qt3support.h"

#ifdef QT4

#include <QPainter>
#include <QMouseEvent>

#else

#include <qpainter.h>

#endif


#include "pixmap_button.h"
#include "embed.h"



pixmapButton::pixmapButton( QWidget * _parent, engine * _engine ) :
	automatableButton( _parent, _engine ),
	m_activePixmap(),
	m_inactivePixmap(),
	m_bgPixmap()
{
	setActiveGraphic( embed::getIconPixmap( "led_yellow" ) );
	setInactiveGraphic( embed::getIconPixmap( "led_off" ), FALSE );

#ifndef QT4
	setBackgroundMode( Qt::NoBackground );
#endif

	//setCheckable( TRUE );
}




pixmapButton::~pixmapButton()
{
}




void pixmapButton::paintEvent( QPaintEvent * )
{
#ifdef QT4
	QPainter p( this );
#else
	QPixmap draw_pm( rect().size() );
	draw_pm.fill( this, rect().topLeft() );

	QPainter p( &draw_pm, this );
#endif

	if( !m_bgPixmap.isNull() )
	{
		p.drawPixmap( 0, 0, m_bgPixmap );
	}

	if( isChecked() )
	{
		if( !m_activePixmap.isNull() )
		{
			p.drawPixmap( 0, 0, m_activePixmap );
		}
	}
	else if( !m_inactivePixmap.isNull() )
	{
		p.drawPixmap( 0, 0, m_inactivePixmap );
	}

#ifndef QT4
	// and blit all the drawn stuff on the screen...
	bitBlt( this, rect().topLeft(), &draw_pm );
#endif
}





void pixmapButton::mousePressEvent( QMouseEvent * _me )
{
	if( _me->button() == Qt::RightButton )
	{
		emit( clickedRight() );
		_me->accept();
	}
	else
	{
		automatableButton::mousePressEvent( _me );
	}
}




void pixmapButton::mouseDoubleClickEvent( QMouseEvent * _me )
{
	emit doubleClicked();
	_me->accept();
}




void pixmapButton::setActiveGraphic( const QPixmap & _pm )
{
	m_activePixmap = _pm;
	resize( m_activePixmap.width(), m_activePixmap.height() );
}




void pixmapButton::setInactiveGraphic( const QPixmap & _pm, bool _update )
{
	m_inactivePixmap = _pm;
	if( _update )
	{
		update();
	}
}




void pixmapButton::setBgGraphic( const QPixmap & _pm )
{
	m_bgPixmap = _pm;
}



#include "pixmap_button.moc"


#endif
