#include "pluginInterface.h"

#include "elements.h"


Q_EXPORT_PLUGIN2(qreal_editors, Plugin)

Plugin::Plugin()
{
	initPlugin();
}

void Plugin::initPlugin()
{
	initNameMap();
	initMouseGestureMap();
	initPropertyMap();
	initPropertyDefaultsMap();
}

void Plugin::initNameMap()
{
	diagramNameMap["SimpleEditor"] = QString::fromUtf8("Простой редактор");

	diagramNodeNameMap["SimpleEditor"] = "SimpleDiagram";

	elementsNameMap["SimpleEditor"]["SimpleDiagram"] = QString::fromUtf8("Простая диаграмма");
	elementsNameMap["SimpleEditor"]["SimpleEdge"] = QString::fromUtf8("Простая связь");
	elementsNameMap["SimpleEditor"]["SimpleNode"] = QString::fromUtf8("Простой элемент");


}

void Plugin::initMouseGestureMap()
{

}

void Plugin::initPropertyMap()
{

}

void Plugin::initPropertyDefaultsMap()
{

}

void Plugin::initParentsMap()
{

}

QStringList Plugin::diagrams() const
{
	return diagramNameMap.keys();
}

QStringList Plugin::elements(QString const &diagram) const
{
	return elementsNameMap[diagram].keys();
}

QString Plugin::elementDescription(QString const &diagram, QString const &element) const
{
	return elementsDescriptionMap[diagram][element];
}

QString Plugin::propertyDescription(QString const &diagram, QString const &element, QString const &property) const
{
	return propertiesDescriptionMap[diagram][element][property];
}

QString Plugin::propertyDisplayedName(QString const &diagram, QString const &element, QString const &property) const
{
	return propertiesDisplayedNamesMap[diagram][element][property];
}

bool Plugin::isParentOf(QString const &parentDiagram, QString const &parentElement, QString const &childDiagram, QString const &childElement) const
{
	if (childDiagram == parentDiagram && childElement == parentElement)
		return true;
	if (parentsMap[childDiagram][childElement].contains(qMakePair(parentDiagram, parentElement)))
		return true;
	typedef QPair<QString, QString> StringPair;
	foreach (StringPair const &pair, parentsMap[childDiagram][childElement])
		if (isParentOf(parentDiagram, parentElement, pair.first, pair.second))
			return true;
	return false;
}

QList<QPair<QString, QString> > Plugin::getParentsOf(QString const &diagram, QString const &element) const
{
	return parentsMap[diagram][element];
}

QStringList Plugin::diagramPaletteGroups(QString const &diagram) const
{
	return paletteGroupsMap[diagram].keys();
}

QStringList Plugin::diagramPaletteGroupList(QString const &diagram, QString const &group) const
{
	return paletteGroupsMap[diagram][group];
} 

QStringList Plugin::getPropertiesWithDefaultValues(QString const &element) const
{
	return propertyDefault[element].keys();
}

QString Plugin::diagramPaletteGroupDescription(QString const &diagram, QString const &group) const
{
	return paletteGroupsDescriptionMap[diagram][group];
}

QIcon Plugin::getIcon(SdfIconEngineV2Interface *engine) const
{
	return QIcon(engine);
}

QString Plugin::editorName() const
{
	 return " Editor";
}

QString Plugin::diagramName(QString const &diagram) const
{
	return diagramNameMap[diagram];
}

QString Plugin::diagramNodeName(QString const &diagram) const
{
	return diagramNodeNameMap[diagram];
}

QString Plugin::elementName(QString const &diagram, QString const &element) const
{
	return elementsNameMap[diagram][element];
}

QString Plugin::elementMouseGesture(QString const &diagram, QString const &element) const
{
	return elementMouseGesturesMap[diagram][element];
}

ElementImpl* Plugin::getGraphicalObject(QString const &/*diagram*/, QString const &element) const
{
	if (element == "SimpleDiagram")
		return new SimpleDiagram();
	else if (element == "SimpleEdge")
		return new SimpleEdge();
	else if (element == "SimpleNode")
		return new SimpleNode();


	Q_ASSERT(!"Request for creation of an element with unknown name");
	return NULL;
}

QStringList Plugin::getPropertyNames(QString const &/*diagram*/, QString const &element) const
{
	return propertyTypes[element].keys();
}

QStringList Plugin::getReferenceProperties(QString const &/*diagram*/, QString const &element) const
{
	QStringList result;
	Q_UNUSED(element)

	return result;
}

QStringList Plugin::getTypesContainedBy(QString const &element) const
{
	QStringList result;
	Q_UNUSED(element)

	return result;
}

QStringList Plugin::getConnectedTypes(QString const &element) const
{
	QStringList result;
	Q_UNUSED(element)

	return result;
}

QStringList Plugin::getUsedTypes(QString const &element) const
{
	QStringList result;
	Q_UNUSED(element)

	return result;
}

QList<QPair<QPair<QString,QString>,QPair<bool,QString> > > Plugin::getPossibleEdges(QString const &element) const
{
	QList<QPair<QPair<QString,QString>,QPair<bool,QString> > > result;
	Q_UNUSED(element)

	return result;
}

//(-1) means "edge", (+1) means "node"
int Plugin::isNodeOrEdge(QString const &element) const
{
	if (element == "SimpleDiagram")
		return 1;
	else if (element == "SimpleEdge")
		return -1;
	else if (element == "SimpleNode")
		return 1;

	return 0;
}
QStringList Plugin::getEnumValues(QString name) const
{
	QStringList result;

	return result;
}

QString Plugin::getPropertyType(QString const &element, QString const &property) const
{
	return propertyTypes[element][property];
}

QString Plugin::getPropertyDefaultValue(QString const &element, QString const &property) const
{
	return propertyDefault[element][property];
}

QList<qReal::ListenerInterface*> Plugin::listeners() const
{
	QList<qReal::ListenerInterface*> result;
	return result;
}
