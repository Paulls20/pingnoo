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

#ifndef NEDRYSOFT_CORE_IROUTEENGINEFACTORY_H
#define NEDRYSOFT_CORE_IROUTEENGINEFACTORY_H

#include "ComponentSystem/IInterface.h"
#include "Core/Core.h"
#include "CoreSpec.h"
#include "IConfiguration.h"

namespace Nedrysoft::Core {
    class IRouteEngine;

    /**
     * @brief       The IRouteEngineFactory interface definition of a route engine factory.
     *
     * @details     Creates instances of route engines.  Route engines are not instantiaed directly, instead the
     *              application can find all route engine factories and select a route engine factory to create
     *              route engines with.
     */
    class NEDRYSOFT_CORE_DLLSPEC IRouteEngineFactory :
            public Nedrysoft::ComponentSystem::IInterface,
            public Nedrysoft::Core::IConfiguration {

        private:
            Q_OBJECT

            Q_INTERFACES(Nedrysoft::ComponentSystem::IInterface)
            Q_INTERFACES(Nedrysoft::Core::IConfiguration)

        public:
            /**
             * @brief       Destroys the IRouteEngineFactory.
             */
            virtual ~IRouteEngineFactory() = default;

            /**
             * @brief       Creates a route engine instance.
             *
             * @details     Creates and returns a route engine instance.  The instance is owned by the factory
             *              and is responsible for its life cycle.
             *
             * @returns     the route engine instance.
             */
            virtual Nedrysoft::Core::IRouteEngine *createEngine() = 0;

            /**
             * @brief       Returns the descriptive name of the route engine.
             *
             * @brief       Returns the description of the route engine, used to display the name of the engine
             *              to the user.
             *
             * @returns     the descriptive name of the route engine.
             */
            virtual QString description() = 0;
    };
}

Q_DECLARE_INTERFACE(Nedrysoft::Core::IRouteEngineFactory, "com.nedrysoft.core.IRouteEngineFactory/1.0.0")

#endif // NEDRYSOFT_CORE_IROUTEENGINEFACTORY_H