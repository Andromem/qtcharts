/****************************************************************************
**
** Copyright (C) 2012 Digia Plc
** All rights reserved.
** For any questions to Digia, please use contact form at http://qt.digia.com
**
** This file is part of the Qt Commercial Charts Add-on.
**
** $QT_BEGIN_LICENSE$
** Licensees holding valid Qt Commercial licenses may use this file in
** accordance with the Qt Commercial License Agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.
**
** If you have questions regarding the use of this file, please use
** contact form at http://qt.digia.com
** $QT_END_LICENSE$
**
****************************************************************************/

#include "declarativesplineseries.h"
#include "declarativechart.h"
#include <QChart>
#include "declarativexypoint.h"

QTCOMMERCIALCHART_BEGIN_NAMESPACE

/*!
    \qmlclass SplineSeries QSplineSeries

    \section1 Example Usage

    \beginfloatleft
    \image demos_qmlchart3.png
    \endfloat
    \clearfloat

    The following QML shows how to create a simple spline chart:
    \snippet ../demos/qmlchart/qml/qmlchart/View3.qml 1
*/

DeclarativeSplineSeries::DeclarativeSplineSeries(QObject *parent) :
    QSplineSeries(parent)
{
    connect(this, SIGNAL(pointAdded(int)), this, SLOT(handleCountChanged(int)));
    connect(this, SIGNAL(pointRemoved(int)), this, SLOT(handleCountChanged(int)));
}

QXYSeries *DeclarativeSplineSeries::xySeries()
{
    return this;
}

void DeclarativeSplineSeries::handleCountChanged(int index)
{
    Q_UNUSED(index)
    emit countChanged(points().count());
}

QDeclarativeListProperty<QObject> DeclarativeSplineSeries::declarativeChildren()
{
    return QDeclarativeListProperty<QObject>(this, 0, &appendDeclarativeChildren);
}

void DeclarativeSplineSeries::appendDeclarativeChildren(QDeclarativeListProperty<QObject> *list, QObject *element)
{
    Q_UNUSED(list)
    Q_UNUSED(element)
    // Empty implementation, childs are parsed in componentComplete
}

#include "moc_declarativesplineseries.cpp"

QTCOMMERCIALCHART_END_NAMESPACE
