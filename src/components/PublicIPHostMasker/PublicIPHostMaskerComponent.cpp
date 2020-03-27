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

#include "PublicIPHostMaskerComponent.h"
#include "PublicIPHostMasker.h"
#include "ComponentSystem/IComponentManager.h"
#include <QDebug>

PublicIPHostMaskerComponent::PublicIPHostMaskerComponent()
{
    m_hostMasker = nullptr;
}

PublicIPHostMaskerComponent::~PublicIPHostMaskerComponent()
{
    if (m_hostMasker) {
        FizzyAde::ComponentSystem::removeObject(m_hostMasker);

        delete m_hostMasker;
    }
}

void PublicIPHostMaskerComponent::initialiseEvent()
{
    m_hostMasker = new FizzyAde::PublicIPHostMasker::PublicIPHostMasker();

    FizzyAde::ComponentSystem::addObject(m_hostMasker);
}