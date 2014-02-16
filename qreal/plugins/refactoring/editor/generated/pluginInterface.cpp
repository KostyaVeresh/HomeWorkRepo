#include "pluginInterface.h"

#include "elements.h"


RefactoringEditorPlugin::RefactoringEditorPlugin()
{
	initPlugin();
}

void RefactoringEditorPlugin::initPlugin()
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

void RefactoringEditorPlugin::initNameMap()
{
	mDiagramNameMap["RefactoringDiagram"] = QString::fromUtf8("Refactoring Diagram");
	mDiagramNodeNameMap["RefactoringDiagram"] = "refactoringDiagramNode";

	mElementsNameMap["RefactoringDiagram"]["AfterBlock"] = QString::fromUtf8("After Block");
	mElementsNameMap["RefactoringDiagram"]["BeforeBlock"] = QString::fromUtf8("Before Block");
	mElementsNameMap["RefactoringDiagram"]["Element"] = QString::fromUtf8("Element");
	mElementsNameMap["RefactoringDiagram"]["FromBeforeToAter"] = QString::fromUtf8("From Before To After");
	mElementsNameMap["RefactoringDiagram"]["Link"] = QString::fromUtf8("Link");
	mElementsNameMap["RefactoringDiagram"]["RefactoringDiagramNode"] = QString::fromUtf8("Refactoring Diagram");
	mElementsNameMap["RefactoringDiagram"]["SelectedSegment"] = QString::fromUtf8("Selected segment");
}

void RefactoringEditorPlugin::initPaletteGroupsMap()
{
	{
		QStringList groupElements;
		groupElements << QString::fromUtf8("RefactoringDiagramNode");
		groupElements << QString::fromUtf8("FromBeforeToAter");
		groupElements << QString::fromUtf8("AfterBlock");
		groupElements << QString::fromUtf8("BeforeBlock");
		mPaletteGroupsMap[QString::fromUtf8("RefactoringDiagram")].append(qMakePair(QString::fromUtf8("Refactoring Rule Elements"), groupElements));
	}
	{
		QStringList groupElements;
		groupElements << QString::fromUtf8("Element");
		groupElements << QString::fromUtf8("Link");
		groupElements << QString::fromUtf8("SelectedSegment");
		mPaletteGroupsMap[QString::fromUtf8("RefactoringDiagram")].append(qMakePair(QString::fromUtf8("Basic Elements"), groupElements));
	}
}

void RefactoringEditorPlugin::initPaletteGroupsDescriptionMap()
{
}

void RefactoringEditorPlugin::initMouseGestureMap()
{
}

void RefactoringEditorPlugin::initPropertyMap()
{
}

void RefactoringEditorPlugin::initPropertyDefaultsMap()
{
}

void RefactoringEditorPlugin::initDescriptionMap()
{
}

void RefactoringEditorPlugin::initParentsMap()
{
}

void RefactoringEditorPlugin::initShallPaletteBeSortedMap()
{
	mShallPaletteBeSortedMap[QString::fromUtf8("RefactoringDiagram")] = true;
}

void RefactoringEditorPlugin::initExplosionsMap()
{
}

QStringList RefactoringEditorPlugin::diagrams() const
{
	return mDiagramNameMap.keys();
}

QStringList RefactoringEditorPlugin::diagramPaletteGroups(QString const &diagram) const
{
	QStringList result;
	for (QPair<QString, QStringList> const &group : mPaletteGroupsMap[diagram]) {
		result << group.first;
	}

	return result;
}

QStringList RefactoringEditorPlugin::diagramPaletteGroupList(QString const &diagram, QString const &group) const
{
	for (QPair<QString, QStringList> const &ourGroup : mPaletteGroupsMap[diagram]) {
		if (ourGroup.first == group) {
			return ourGroup.second;
		}
	}

	return QStringList();
}

QString RefactoringEditorPlugin::diagramPaletteGroupDescription(QString const &diagram, QString const &group) const
{
	return mPaletteGroupsDescriptionMap[diagram][group];
}

bool RefactoringEditorPlugin::shallPaletteBeSorted(QString const &diagram) const
{
	return mShallPaletteBeSortedMap[diagram];
}

QStringList RefactoringEditorPlugin::elements(QString const &diagram) const
{
	return mElementsNameMap[diagram].keys();
}

QStringList RefactoringEditorPlugin::getPropertiesWithDefaultValues(QString const &element) const
{
	return mPropertyDefault[element].keys();
}

QString RefactoringEditorPlugin::editorName() const
{
	 return "RefactoringEditor Editor";
}

QString RefactoringEditorPlugin::diagramName(QString const &diagram) const
{
	return mDiagramNameMap[diagram];
}

QString RefactoringEditorPlugin::diagramNodeName(QString const &diagram) const
{
	return mDiagramNodeNameMap[diagram];
}

QString RefactoringEditorPlugin::elementName(QString const &diagram, QString const &element) const
{
	return mElementsNameMap[diagram][element];
}

QString RefactoringEditorPlugin::elementDescription(QString const &diagram, QString const &element)const
{
	return mElementsDescriptionMap[diagram][element];
}

QString RefactoringEditorPlugin::propertyDescription(QString const &diagram, QString const &element, QString const &property) const
{
	return mPropertiesDescriptionMap[diagram][element][property];
}

QString RefactoringEditorPlugin::propertyDisplayedName(QString const &diagram, QString const &element, QString const &property) const
{
	return mPropertiesDisplayedNamesMap[diagram][element][property];
}

QString RefactoringEditorPlugin::elementMouseGesture(QString const &diagram, QString const &element) const
{
	return mElementMouseGesturesMap[diagram][element];
}

QList<qReal::EditorInterface::ExplosionData>RefactoringEditorPlugin::explosions(QString const &diagram, QString const &element) const 
{
	return mExplosionsMap[diagram][element];
}

qReal::ElementImpl* RefactoringEditorPlugin::getGraphicalObject(QString const &/*diagram*/, QString const &element) const
{
	if (element == "AfterBlock") {
		return new AfterBlock();
	}
	else if (element == "BeforeBlock") {
		return new BeforeBlock();
	}
	else if (element == "Element") {
		return new Element();
	}
	else if (element == "FromBeforeToAter") {
		return new FromBeforeToAter();
	}
	else if (element == "Link") {
		return new Link();
	}
	else if (element == "RefactoringDiagramNode") {
		return new RefactoringDiagramNode();
	}
	else if (element == "SelectedSegment") {
		return new SelectedSegment();
	}
	else {
		Q_ASSERT(!"Request for creation of an element with unknown name");
		return NULL;
	}
}

bool RefactoringEditorPlugin::isParentOf(QString const &parentDiagram, QString const &parentElement, QString const &childDiagram, QString const &childElement) const
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
QList<QPair<QString, QString> > RefactoringEditorPlugin::getParentsOf(QString const &diagram, QString const &element) const
{
	return mParentsMap[diagram][element];
}
QStringList RefactoringEditorPlugin::getPropertyNames(QString const &/*diagram*/, QString const &element) const
{
	QStringList result;
	if (element == "AfterBlock") {
	}
	else if (element == "BeforeBlock") {
	}
	else if (element == "Element") {
		result  << "ID";
	}
	else if (element == "FromBeforeToAter") {
	}
	else if (element == "Link") {
		result  << "ID";
	}
	else if (element == "RefactoringDiagramNode") {
	}
	else if (element == "SelectedSegment") {
		result  << "ID";
	}
	return result;
}

QStringList RefactoringEditorPlugin::getPortTypes(QString const &/*diagram*/, QString const &element) const
{
	QStringList result;
	if (element == "AfterBlock") {
		result << "NonTyped";
	}
	else if (element == "BeforeBlock") {
		result << "NonTyped";
	}
	else if (element == "Element") {
		result << "NonTyped";
	}
	else if (element == "FromBeforeToAter") {
		result << "NonTyped";
	}
	else if (element == "RefactoringDiagramNode") {
		result << "NonTyped";
	}
	else if (element == "SelectedSegment") {
		result << "NonTyped";
	}
	return result;
}

QStringList RefactoringEditorPlugin::getReferenceProperties(QString const &/*diagram*/, QString const &element) const
{
	QStringList result;
	if (element == "AfterBlock") {
	}
	else if (element == "BeforeBlock") {
	}
	else if (element == "Element") {
	}
	else if (element == "FromBeforeToAter") {
	}
	else if (element == "Link") {
	}
	else if (element == "RefactoringDiagramNode") {
	}
	else if (element == "SelectedSegment") {
	}
	return result;
}

QStringList RefactoringEditorPlugin::getTypesContainedBy(QString const &element) const
{
	QStringList result;
	if (element == "AfterBlock") {
		result << "Element" << "Link" << "Subprogram" ;
	}
	else if (element == "BeforeBlock") {
		result << "Element" << "SelectedSegment" << "Link" << "Subprogram" ;
	}
	return result;
}

QList<QPair<QPair<QString,QString>,QPair<bool,QString> > > RefactoringEditorPlugin::getPossibleEdges(QString const &element) const
{
	QList<QPair<QPair<QString,QString>,QPair<bool,QString> > > result;
	Q_UNUSED(element);
	return result;
}

//(-1) means "edge", (+1) means "node"
int RefactoringEditorPlugin::isNodeOrEdge(QString const &element) const
{
	if (element == "AfterBlock")
		return 1;
	else if (element == "BeforeBlock")
		return 1;
	else if (element == "Element")
		return 1;
	else if (element == "FromBeforeToAter")
		return 1;
	else if (element == "Link")
		return -1;
	else if (element == "RefactoringDiagramNode")
		return 1;
	else if (element == "SelectedSegment")
		return 1;
	return 0;
}
QString RefactoringEditorPlugin::getGroupsXML() const 
{
	return QString::fromUtf8("");
}

QStringList RefactoringEditorPlugin::getEnumValues(QString name) const 
{
	QStringList result;
	Q_UNUSED(name);
	return result;
}

QString RefactoringEditorPlugin::getPropertyType(QString const &element, QString const &property) const
{
	return mPropertyTypes[element][property];
}

QString RefactoringEditorPlugin::getPropertyDefaultValue(QString const &element, QString const &property) const
{
	return mPropertyDefault[element][property];
}

QList<qReal::ListenerInterface*> RefactoringEditorPlugin::listeners() const
{
	QList<qReal::ListenerInterface*> result;
	return result;
}
