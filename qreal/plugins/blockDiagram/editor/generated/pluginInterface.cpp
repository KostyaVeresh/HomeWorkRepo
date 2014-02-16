#include "pluginInterface.h"

#include "elements.h"


BlockDiagramMetamodelPlugin::BlockDiagramMetamodelPlugin()
{
	initPlugin();
}

void BlockDiagramMetamodelPlugin::initPlugin()
{
	initNameMap();
	initMouseGestureMap();
	initPropertyMap();
	initPropertyDefaultsMap();
	initDescriptionMap();
	initParentsMap();
	initPaletteGroupsMap();
	initPaletteGroupsDescriptionMap();
	initShallPaletteBeSortedMap();
	initExplosionsMap();
}

void BlockDiagramMetamodelPlugin::initNameMap()
{
	mDiagramNameMap["BlockDiagram"] = QString::fromUtf8("Block Diagram");
	mDiagramNodeNameMap["BlockDiagram"] = "BlockDiagramNode";

	mElementsNameMap["BlockDiagram"]["ActionElement"] = QString::fromUtf8("Action");
	mElementsNameMap["BlockDiagram"]["BlockDiagramNode"] = QString::fromUtf8("Block Diagram");
	mElementsNameMap["BlockDiagram"]["BlockFinalNode"] = QString::fromUtf8("Final Node");
	mElementsNameMap["BlockDiagram"]["ConditionControlFlow"] = QString::fromUtf8("Condition Control Flow");
	mElementsNameMap["BlockDiagram"]["ConditionNode"] = QString::fromUtf8("Condition Node");
	mElementsNameMap["BlockDiagram"]["ControlFlow"] = QString::fromUtf8("Control Flow");
	mElementsNameMap["BlockDiagram"]["InitialNode"] = QString::fromUtf8("Initial Node");
}

void BlockDiagramMetamodelPlugin::initPaletteGroupsMap()
{
	{
		QStringList groupElements;
		groupElements << QString::fromUtf8("ConditionNode");
		groupElements << QString::fromUtf8("BlockDiagramNode");
		groupElements << QString::fromUtf8("ActionElement");
		groupElements << QString::fromUtf8("InitialNode");
		groupElements << QString::fromUtf8("ConditionControlFlow");
		groupElements << QString::fromUtf8("ControlFlow");
		groupElements << QString::fromUtf8("BlockFinalNode");
		mPaletteGroupsMap[QString::fromUtf8("BlockDiagram")].append(qMakePair(QString::fromUtf8("Элементы"), groupElements));
	}
}

void BlockDiagramMetamodelPlugin::initPaletteGroupsDescriptionMap()
{
}

void BlockDiagramMetamodelPlugin::initMouseGestureMap()
{
}

void BlockDiagramMetamodelPlugin::initPropertyMap()
{
	mPropertyTypes["BlockDiagramNode"]["isView"] = "Bool";
	mPropertyTypes["ConditionControlFlow"]["type"] = "Bool";
}

void BlockDiagramMetamodelPlugin::initPropertyDefaultsMap()
{
	mPropertyDefault["ConditionControlFlow"]["type"] = QString::fromUtf8("false");
}

void BlockDiagramMetamodelPlugin::initDescriptionMap()
{
}

void BlockDiagramMetamodelPlugin::initParentsMap()
{
	mParentsMap["BlockDiagram"]["BlockDiagramNode"]
		<< qMakePair(QString("BlockDiagram"), QString("Diagram"))
	;
}

void BlockDiagramMetamodelPlugin::initShallPaletteBeSortedMap()
{
	mShallPaletteBeSortedMap[QString::fromUtf8("BlockDiagram")] = true;
}

void BlockDiagramMetamodelPlugin::initExplosionsMap()
{
}

QStringList BlockDiagramMetamodelPlugin::diagrams() const
{
	return mDiagramNameMap.keys();
}

QStringList BlockDiagramMetamodelPlugin::diagramPaletteGroups(QString const &diagram) const
{
	QStringList result;
	for (QPair<QString, QStringList> const &group : mPaletteGroupsMap[diagram]) {
		result << group.first;
	}

	return result;
}

QStringList BlockDiagramMetamodelPlugin::diagramPaletteGroupList(QString const &diagram, QString const &group) const
{
	for (QPair<QString, QStringList> const &ourGroup : mPaletteGroupsMap[diagram]) {
		if (ourGroup.first == group) {
			return ourGroup.second;
		}
	}

	return QStringList();
}

QString BlockDiagramMetamodelPlugin::diagramPaletteGroupDescription(QString const &diagram, QString const &group) const
{
	return mPaletteGroupsDescriptionMap[diagram][group];
}

bool BlockDiagramMetamodelPlugin::shallPaletteBeSorted(QString const &diagram) const
{
	return mShallPaletteBeSortedMap[diagram];
}

QStringList BlockDiagramMetamodelPlugin::elements(QString const &diagram) const
{
	return mElementsNameMap[diagram].keys();
}

QStringList BlockDiagramMetamodelPlugin::getPropertiesWithDefaultValues(QString const &element) const
{
	return mPropertyDefault[element].keys();
}

QString BlockDiagramMetamodelPlugin::editorName() const
{
	 return "BlockDiagramMetamodel Editor";
}

QString BlockDiagramMetamodelPlugin::diagramName(QString const &diagram) const
{
	return mDiagramNameMap[diagram];
}

QString BlockDiagramMetamodelPlugin::diagramNodeName(QString const &diagram) const
{
	return mDiagramNodeNameMap[diagram];
}

QString BlockDiagramMetamodelPlugin::elementName(QString const &diagram, QString const &element) const
{
	return mElementsNameMap[diagram][element];
}

QString BlockDiagramMetamodelPlugin::elementDescription(QString const &diagram, QString const &element)const
{
	return mElementsDescriptionMap[diagram][element];
}

QString BlockDiagramMetamodelPlugin::propertyDescription(QString const &diagram, QString const &element, QString const &property) const
{
	return mPropertiesDescriptionMap[diagram][element][property];
}

QString BlockDiagramMetamodelPlugin::propertyDisplayedName(QString const &diagram, QString const &element, QString const &property) const
{
	return mPropertiesDisplayedNamesMap[diagram][element][property];
}

QString BlockDiagramMetamodelPlugin::elementMouseGesture(QString const &diagram, QString const &element) const
{
	return mElementMouseGesturesMap[diagram][element];
}

QList<qReal::EditorInterface::ExplosionData>BlockDiagramMetamodelPlugin::explosions(QString const &diagram, QString const &element) const 
{
	return mExplosionsMap[diagram][element];
}

qReal::ElementImpl* BlockDiagramMetamodelPlugin::getGraphicalObject(QString const &/*diagram*/, QString const &element) const
{
	if (element == "ActionElement") {
		return new ActionElement();
	}
	else if (element == "BlockDiagramNode") {
		return new BlockDiagramNode();
	}
	else if (element == "BlockFinalNode") {
		return new BlockFinalNode();
	}
	else if (element == "ConditionControlFlow") {
		return new ConditionControlFlow();
	}
	else if (element == "ConditionNode") {
		return new ConditionNode();
	}
	else if (element == "ControlFlow") {
		return new ControlFlow();
	}
	else if (element == "InitialNode") {
		return new InitialNode();
	}
	else {
		Q_ASSERT(!"Request for creation of an element with unknown name");
		return NULL;
	}
}

bool BlockDiagramMetamodelPlugin::isParentOf(QString const &parentDiagram, QString const &parentElement, QString const &childDiagram, QString const &childElement) const
{
	if (childDiagram == parentDiagram && childElement == parentElement)
		return true;
	if (mParentsMap[childDiagram][childElement].contains(qMakePair(parentDiagram, parentElement)))
		return true;
	typedef QPair<QString, QString> StringPair;
	foreach (StringPair const &pair, mParentsMap[childDiagram][childElement])
		if (isParentOf(parentDiagram, parentElement, pair.first, pair.second))
			return true;
	return false;
}
QList<QPair<QString, QString> > BlockDiagramMetamodelPlugin::getParentsOf(QString const &diagram, QString const &element) const
{
	return mParentsMap[diagram][element];
}
QStringList BlockDiagramMetamodelPlugin::getPropertyNames(QString const &/*diagram*/, QString const &element) const
{
	QStringList result;
	if (element == "ActionElement") {
		result  << "process";
	}
	else if (element == "BlockDiagramNode") {
		result  << "isView" << "language";
	}
	else if (element == "BlockFinalNode") {
	}
	else if (element == "ConditionControlFlow") {
		result  << "type";
	}
	else if (element == "ConditionNode") {
		result  << "condition";
	}
	else if (element == "ControlFlow") {
	}
	else if (element == "InitialNode") {
	}
	return result;
}

QStringList BlockDiagramMetamodelPlugin::getPortTypes(QString const &/*diagram*/, QString const &element) const
{
	QStringList result;
	if (element == "ActionElement") {
		result << "NonTyped";
	}
	else if (element == "BlockDiagramNode") {
		result << "NonTyped";
	}
	else if (element == "BlockFinalNode") {
		result << "NonTyped";
	}
	else if (element == "ConditionNode") {
		result << "NonTyped";
	}
	else if (element == "InitialNode") {
		result << "NonTyped";
	}
	return result;
}

QStringList BlockDiagramMetamodelPlugin::getReferenceProperties(QString const &/*diagram*/, QString const &element) const
{
	QStringList result;
	if (element == "ActionElement") {
	}
	else if (element == "BlockDiagramNode") {
	}
	else if (element == "BlockFinalNode") {
	}
	else if (element == "ConditionControlFlow") {
	}
	else if (element == "ConditionNode") {
	}
	else if (element == "ControlFlow") {
	}
	else if (element == "InitialNode") {
	}
	return result;
}

QStringList BlockDiagramMetamodelPlugin::getTypesContainedBy(QString const &element) const
{
	QStringList result;
	if (element == "BlockDiagramNode") {
		result << "ActionElement" << "BlockFinalNode" << "ControlFlow" << "InitialNode" << "ConditionNode" ;
	}
	return result;
}

QList<QPair<QPair<QString,QString>,QPair<bool,QString> > > BlockDiagramMetamodelPlugin::getPossibleEdges(QString const &element) const
{
	QList<QPair<QPair<QString,QString>,QPair<bool,QString> > > result;
	if (element == "ConditionControlFlow") {
		result << qMakePair(qMakePair(QString("ConditionNode"),QString("ConditionNode")),qMakePair(true,QString("ConditionControlFlow"))) << qMakePair(qMakePair(QString("ConditionNode"),QString("ActionElement")),qMakePair(true,QString("ConditionControlFlow"))) << qMakePair(qMakePair(QString("ConditionNode"),QString("BlockFinalNode")),qMakePair(true,QString("ConditionControlFlow")));
	}
	else if (element == "ControlFlow") {
		result << qMakePair(qMakePair(QString("InitialNode"),QString("ConditionNode")),qMakePair(true,QString("ControlFlow"))) << qMakePair(qMakePair(QString("InitialNode"),QString("BlockFinalNode")),qMakePair(true,QString("ControlFlow"))) << qMakePair(qMakePair(QString("InitialNode"),QString("ActionElement")),qMakePair(true,QString("ControlFlow"))) << qMakePair(qMakePair(QString("ActionElement"),QString("BlockDiagramNode")),qMakePair(true,QString("ControlFlow"))) << qMakePair(qMakePair(QString("ActionElement"),QString("ActionElement")),qMakePair(true,QString("ControlFlow"))) << qMakePair(qMakePair(QString("ActionElement"),QString("ConditionNode")),qMakePair(true,QString("ControlFlow"))) << qMakePair(qMakePair(QString("ActionElement"),QString("BlockFinalNode")),qMakePair(true,QString("ControlFlow")));
	}
	return result;
}

//(-1) means "edge", (+1) means "node"
int BlockDiagramMetamodelPlugin::isNodeOrEdge(QString const &element) const
{
	if (element == "ActionElement")
		return 1;
	else if (element == "BlockDiagramNode")
		return 1;
	else if (element == "BlockFinalNode")
		return 1;
	else if (element == "ConditionControlFlow")
		return -1;
	else if (element == "ConditionNode")
		return 1;
	else if (element == "ControlFlow")
		return -1;
	else if (element == "InitialNode")
		return 1;
	return 0;
}
QString BlockDiagramMetamodelPlugin::getGroupsXML() const 
{
	return QString::fromUtf8("");
}

QStringList BlockDiagramMetamodelPlugin::getEnumValues(QString name) const 
{
	QStringList result;
	if (name == "CallConcurrencyKind")
		result << QString::fromUtf8("sequential") << QString::fromUtf8("guarded") << QString::fromUtf8("concurrent");
	else if (name == "ParameterDirectionKind")
		result << QString::fromUtf8("in") << QString::fromUtf8("inout") << QString::fromUtf8("out") << QString::fromUtf8("return");
	else if (name == "AggregationKind")
		result << QString::fromUtf8("none") << QString::fromUtf8("shared") << QString::fromUtf8("composite");
	else if (name == "Bool")
		result << QString::fromUtf8("false") << QString::fromUtf8("true");
	else if (name == "VisibilityKind")
		result << QString::fromUtf8("private") << QString::fromUtf8("protected") << QString::fromUtf8("public") << QString::fromUtf8("package");
	return result;
}

QString BlockDiagramMetamodelPlugin::getPropertyType(QString const &element, QString const &property) const
{
	return mPropertyTypes[element][property];
}

QString BlockDiagramMetamodelPlugin::getPropertyDefaultValue(QString const &element, QString const &property) const
{
	return mPropertyDefault[element][property];
}

QList<qReal::ListenerInterface*> BlockDiagramMetamodelPlugin::listeners() const
{
	QList<qReal::ListenerInterface*> result;
	return result;
}
