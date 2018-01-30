/****************************************************************************
 *
 *   (c) 2009-2016 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

#include "AirspaceController.h"
#include "AirspaceManager.h"
#include "AirspaceWeatherInfoProvider.h"
#include "AirspaceAdvisoryProvider.h"

#include "QGCApplication.h"
#include "QGCQGeoCoordinate.h"
#include "QmlObjectListModel.h"

AirspaceController::AirspaceController(QObject* parent)
    : QObject(parent)
    , _manager(qgcApp()->toolbox()->airspaceManager())
    , _airspaceVisible(false)
{
}

void
AirspaceController::setROI(QGeoCoordinate center, double radius)
{
    _manager->setROI(center, radius);
}

QString
AirspaceController::providerName()
{
    return _manager->name();
}

AirspaceWeatherInfoProvider*
AirspaceController::weatherInfo()
{
    return _manager->weatherInfo();
}

AirspaceAdvisoryProvider*
AirspaceController::advisories()
{
    return _manager->advisories();
}

AirspaceRulesetsProvider*
AirspaceController::rulesets()
{
    return _manager->rulesets();
}

AirspaceRestrictionProvider*
AirspaceController::airspaces()
{
    return _manager->airspaces();
}