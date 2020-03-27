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

#ifndef FIZZYADE_HOSTIPGEOIPPROVIDER_CACHE_H
#define FIZZYADE_HOSTIPGEOIPPROVIDER_CACHE_H

#include <QSqlDatabase>
#include <QJsonObject>

namespace FizzyAde::HostIPGeoIPProvider
{
    class Cache
    {
    public:
        Cache();
        ~Cache();

        void add(QJsonObject object);
        bool find(const QString &name, QJsonObject &object);

    protected:

    private:

    };
}

#endif // FIZZYADE_HOSTIPGEOIPPROVIDER_CACHE_H