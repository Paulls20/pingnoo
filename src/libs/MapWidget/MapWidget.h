/*
 * Copyright (C) 2020 Adrian Carpenter
 *
 * This file is part of pingnoo (https://github.com/fizzyade/pingnoo)
 * An open source ping path analyser
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FIZZYADE_MAPWIDGET_MAPWIDGET_H
#define FIZZYADE_MAPWIDGET_MAPWIDGET_H

#include <QWidget>
#include <QGridLayout>

#if (defined(FIZZYADE_LIBRARY_MAPWIDGET_EXPORT))
#define FIZZYADE_MAPWIDGET_DLLSPEC Q_DECL_EXPORT
#else
#define FIZZYADE_MAPWIDGET_DLLSPEC Q_DECL_IMPORT
#endif

class QQuickWidget;

namespace FizzyAde::MapWidget
{
    class FIZZYADE_MAPWIDGET_DLLSPEC MapWidget :
        public QWidget
    {
    public:
        MapWidget(QWidget *parent=nullptr);
        ~MapWidget();

    private:
        QQuickWidget *m_mapWidget;
        QGridLayout *m_mapLayout;
    };
}

#endif // FIZZYADE_MAPWIDGET_MAPWIDGET_H