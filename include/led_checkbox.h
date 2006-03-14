/*
 * led_checkbox.h - class ledCheckBox, an improved QCheckBox
 *
 * Copyright (c) 2005-2006 Tobias Doerffel <tobydox/at/users.sourceforge.net>
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


#ifndef _LED_CHECKBOX_H
#define _LED_CHECKBOX_H

#include "automatable_button.h"


class QPixmap;


class ledCheckBox : public automatableButton
{
	Q_OBJECT
public:
	enum ledColors
	{
		YELLOW, GREEN, TOTAL_COLORS
	} ;

	ledCheckBox( const QString & _txt, QWidget * _parent, engine * _engine,
						ledColors _color = YELLOW );
	virtual ~ledCheckBox();


	inline const QString & text( void )
	{
		return( m_text );
	}


protected:
	virtual void paintEvent( QPaintEvent * _pe );


private:
	QPixmap * m_ledOnPixmap;
	QPixmap * m_ledOffPixmap;
	
	QString m_text;

} ;

#endif
