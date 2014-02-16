#include "pluginInterface.h"

#include "elements.h"


RequirementsMetamodelPlugin::RequirementsMetamodelPlugin()
{
	initPlugin();
}

void RequirementsMetamodelPlugin::initPlugin()
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

void RequirementsMetamodelPlugin::initNameMap()
{
	mDiagramNameMap["RequirementsDiagram"] = QString::fromUtf8("Requirements Diagram");
	mDiagramNodeNameMap["RequirementsDiagram"] = "RequirementsDiagramNode";

	mElementsNameMap["RequirementsDiagram"]["Comment"] = QString::fromUtf8("Comment");
	mElementsNameMap["RequirementsDiagram"]["CommentLink"] = QString::fromUtf8("Comment Link");
	mElementsNameMap["RequirementsDiagram"]["RequirementsDiagramNode"] = QString::fromUtf8("Requirements Diagram");
	mElementsNameMap["RequirementsDiagram"]["ReqeP2N"] = QString::fromUtf8("Feature P2N Relationship");
	mElementsNameMap["RequirementsDiagram"]["ReqnConceptAlternative"] = QString::fromUtf8("Concept Alternative");
	mElementsNameMap["RequirementsDiagram"]["ReqnFeatured"] = QString::fromUtf8("Featured Element");
	mElementsNameMap["RequirementsDiagram"]["ReqnLeaf"] = QString::fromUtf8("Leaf");
	mElementsNameMap["RequirementsDiagram"]["ReqnParent"] = QString::fromUtf8("Parent Node");
	mElementsNameMap["RequirementsDiagram"]["ReqnParentAlternative"] = QString::fromUtf8("Parent of Alternative Features");
	mElementsNameMap["RequirementsDiagram"]["ReqnParentMandatory"] = QString::fromUtf8("Parent of Mandatory Features");
	mElementsNameMap["RequirementsDiagram"]["ReqnParentOpAlternative"] = QString::fromUtf8("Parent of Optional-Alternative Features");
	mElementsNameMap["RequirementsDiagram"]["ReqnParentOptional"] = QString::fromUtf8("Parent of Optional Features");
	mElementsNameMap["RequirementsDiagram"]["ReqnParentOr"] = QString::fromUtf8("Parent of Or-Features");
}

void RequirementsMetamodelPlugin::initPaletteGroupsMap()
{
}

void RequirementsMetamodelPlugin::initPaletteGroupsDescriptionMap()
{
}

void RequirementsMetamodelPlugin::initMouseGestureMap()
{
	mElementMouseGesturesMap["RequirementsDiagram"]["RequirementsDiagramNode"] = "10"
			", 0 : 90, 0 : 90, 100 : 10, 100 : 0, 90 : 0, 10 : 100, 10 : 100, 90 : ";
}

void RequirementsMetamodelPlugin::initPropertyMap()
{
	mPropertyTypes["Comment"]["annotatedElement"] = "KernelElement";
	mPropertyTypes["Comment"]["ownedComment"] = "Comment";
	mPropertyTypes["RequirementsDiagramNode"]["isView"] = "Bool";
	mPropertyTypes["ReqeP2N"]["ownedComment"] = "Comment";
	mPropertyTypes["ReqnConceptAlternative"]["ownedComment"] = "Comment";
	mPropertyTypes["ReqnConceptAlternative"]["priority"] = "ReqnPriority";
	mPropertyTypes["ReqnConceptAlternative"]["type"] = "ReqnType";
	mPropertyTypes["ReqnFeatured"]["ownedComment"] = "Comment";
	mPropertyTypes["ReqnFeatured"]["priority"] = "ReqnPriority";
	mPropertyTypes["ReqnFeatured"]["type"] = "ReqnType";
	mPropertyTypes["ReqnLeaf"]["ownedComment"] = "Comment";
	mPropertyTypes["ReqnLeaf"]["priority"] = "ReqnPriority";
	mPropertyTypes["ReqnLeaf"]["type"] = "ReqnType";
	mPropertyTypes["ReqnParent"]["ownedComment"] = "Comment";
	mPropertyTypes["ReqnParent"]["priority"] = "ReqnPriority";
	mPropertyTypes["ReqnParent"]["type"] = "ReqnType";
	mPropertyTypes["ReqnParentAlternative"]["ownedComment"] = "Comment";
	mPropertyTypes["ReqnParentAlternative"]["priority"] = "ReqnPriority";
	mPropertyTypes["ReqnParentAlternative"]["type"] = "ReqnType";
	mPropertyTypes["ReqnParentMandatory"]["ownedComment"] = "Comment";
	mPropertyTypes["ReqnParentMandatory"]["priority"] = "ReqnPriority";
	mPropertyTypes["ReqnParentMandatory"]["type"] = "ReqnType";
	mPropertyTypes["ReqnParentOpAlternative"]["ownedComment"] = "Comment";
	mPropertyTypes["ReqnParentOpAlternative"]["priority"] = "ReqnPriority";
	mPropertyTypes["ReqnParentOpAlternative"]["type"] = "ReqnType";
	mPropertyTypes["ReqnParentOptional"]["ownedComment"] = "Comment";
	mPropertyTypes["ReqnParentOptional"]["priority"] = "ReqnPriority";
	mPropertyTypes["ReqnParentOptional"]["type"] = "ReqnType";
	mPropertyTypes["ReqnParentOr"]["ownedComment"] = "Comment";
	mPropertyTypes["ReqnParentOr"]["priority"] = "ReqnPriority";
	mPropertyTypes["ReqnParentOr"]["type"] = "ReqnType";
}

void RequirementsMetamodelPlugin::initPropertyDefaultsMap()
{
}

void RequirementsMetamodelPlugin::initDescriptionMap()
{
}

void RequirementsMetamodelPlugin::initParentsMap()
{
	mParentsMap["RequirementsDiagram"]["Comment"]
		<< qMakePair(QString("RequirementsDiagram"), QString("KernelElement"))
	;
	mParentsMap["RequirementsDiagram"]["RequirementsDiagramNode"]
		<< qMakePair(QString("RequirementsDiagram"), QString("Diagram"))
	;
	mParentsMap["RequirementsDiagram"]["ReqeP2N"]
		<< qMakePair(QString("RequirementsDiagram"), QString("Relationship"))
	;
	mParentsMap["RequirementsDiagram"]["ReqnConceptAlternative"]
		<< qMakePair(QString("RequirementsDiagram"), QString("ReqnFeatured"))
	;
	mParentsMap["RequirementsDiagram"]["ReqnFeatured"]
		<< qMakePair(QString("RequirementsDiagram"), QString("KernelElement"))
	;
	mParentsMap["RequirementsDiagram"]["ReqnLeaf"]
		<< qMakePair(QString("RequirementsDiagram"), QString("ReqnFeatured"))
	;
	mParentsMap["RequirementsDiagram"]["ReqnParent"]
		<< qMakePair(QString("RequirementsDiagram"), QString("ReqnFeatured"))
	;
	mParentsMap["RequirementsDiagram"]["ReqnParentAlternative"]
		<< qMakePair(QString("RequirementsDiagram"), QString("ReqnParent"))
	;
	mParentsMap["RequirementsDiagram"]["ReqnParentMandatory"]
		<< qMakePair(QString("RequirementsDiagram"), QString("ReqnParent"))
	;
	mParentsMap["RequirementsDiagram"]["ReqnParentOpAlternative"]
		<< qMakePair(QString("RequirementsDiagram"), QString("ReqnParent"))
	;
	mParentsMap["RequirementsDiagram"]["ReqnParentOptional"]
		<< qMakePair(QString("RequirementsDiagram"), QString("ReqnParent"))
	;
	mParentsMap["RequirementsDiagram"]["ReqnParentOr"]
		<< qMakePair(QString("RequirementsDiagram"), QString("ReqnParent"))
	;
}

void RequirementsMetamodelPlugin::initShallPaletteBeSortedMap()
{
	mShallPaletteBeSortedMap[QString::fromUtf8("RequirementsDiagram")] = true;
}

void RequirementsMetamodelPlugin::initExplosionsMap()
{
}

QStringList RequirementsMetamodelPlugin::diagrams() const
{
	return mDiagramNameMap.keys();
}

QStringList RequirementsMetamodelPlugin::diagramPaletteGroups(QString const &diagram) const
{
	QStringList result;
	for (QPair<QString, QStringList> const &group : mPaletteGroupsMap[diagram]) {
		result << group.first;
	}

	return result;
}

QStringList RequirementsMetamodelPlugin::diagramPaletteGroupList(QString const &diagram, QString const &group) const
{
	for (QPair<QString, QStringList> const &ourGroup : mPaletteGroupsMap[diagram]) {
		if (ourGroup.first == group) {
			return ourGroup.second;
		}
	}

	return QStringList();
}

QString RequirementsMetamodelPlugin::diagramPaletteGroupDescription(QString const &diagram, QString const &group) const
{
	return mPaletteGroupsDescriptionMap[diagram][group];
}

bool RequirementsMetamodelPlugin::shallPaletteBeSorted(QString const &diagram) const
{
	return mShallPaletteBeSortedMap[diagram];
}

QStringList RequirementsMetamodelPlugin::elements(QString const &diagram) const
{
	return mElementsNameMap[diagram].keys();
}

QStringList RequirementsMetamodelPlugin::getPropertiesWithDefaultValues(QString const &element) const
{
	return mPropertyDefault[element].keys();
}

QString RequirementsMetamodelPlugin::editorName() const
{
	 return "RequirementsMetamodel Editor";
}

QString RequirementsMetamodelPlugin::diagramName(QString const &diagram) const
{
	return mDiagramNameMap[diagram];
}

QString RequirementsMetamodelPlugin::diagramNodeName(QString const &diagram) const
{
	return mDiagramNodeNameMap[diagram];
}

QString RequirementsMetamodelPlugin::elementName(QString const &diagram, QString const &element) const
{
	return mElementsNameMap[diagram][element];
}

QString RequirementsMetamodelPlugin::elementDescription(QString const &diagram, QString const &element)const
{
	return mElementsDescriptionMap[diagram][element];
}

QString RequirementsMetamodelPlugin::propertyDescription(QString const &diagram, QString const &element, QString const &property) const
{
	return mPropertiesDescriptionMap[diagram][element][property];
}

QString RequirementsMetamodelPlugin::propertyDisplayedName(QString const &diagram, QString const &element, QString const &property) const
{
	return mPropertiesDisplayedNamesMap[diagram][element][property];
}

QString RequirementsMetamodelPlugin::elementMouseGesture(QString const &diagram, QString const &element) const
{
	return mElementMouseGesturesMap[diagram][element];
}

QList<qReal::EditorInterface::ExplosionData>RequirementsMetamodelPlugin::explosions(QString const &diagram, QString const &element) const 
{
	return mExplosionsMap[diagram][element];
}

qReal::ElementImpl* RequirementsMetamodelPlugin::getGraphicalObject(QString const &/*diagram*/, QString const &element) const
{
	if (element == "Comment") {
		return new Comment();
	}
	else if (element == "CommentLink") {
		return new CommentLink();
	}
	else if (element == "RequirementsDiagramNode") {
		return new RequirementsDiagramNode();
	}
	else if (element == "ReqeP2N") {
		return new ReqeP2N();
	}
	else if (element == "ReqnConceptAlternative") {
		return new ReqnConceptAlternative();
	}
	else if (element == "ReqnFeatured") {
		return new ReqnFeatured();
	}
	else if (element == "ReqnLeaf") {
		return new ReqnLeaf();
	}
	else if (element == "ReqnParent") {
		return new ReqnParent();
	}
	else if (element == "ReqnParentAlternative") {
		return new ReqnParentAlternative();
	}
	else if (element == "ReqnParentMandatory") {
		return new ReqnParentMandatory();
	}
	else if (element == "ReqnParentOpAlternative") {
		return new ReqnParentOpAlternative();
	}
	else if (element == "ReqnParentOptional") {
		return new ReqnParentOptional();
	}
	else if (element == "ReqnParentOr") {
		return new ReqnParentOr();
	}
	else {
		Q_ASSERT(!"Request for creation of an element with unknown name");
		return NULL;
	}
}

bool RequirementsMetamodelPlugin::isParentOf(QString const &parentDiagram, QString const &parentElement, QString const &childDiagram, QString const &childElement) const
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
QList<QPair<QString, QString> > RequirementsMetamodelPlugin::getParentsOf(QString const &diagram, QString const &element) const
{
	return mParentsMap[diagram][element];
}
QStringList RequirementsMetamodelPlugin::getPropertyNames(QString const &/*diagram*/, QString const &element) const
{
	QStringList result;
	if (element == "Comment") {
		result  << "annotatedElement" << "body" << "ownedComment";
	}
	else if (element == "CommentLink") {
	}
	else if (element == "RequirementsDiagramNode") {
		result  << "isView" << "language";
	}
	else if (element == "ReqeP2N") {
		result  << "ownedComment";
	}
	else if (element == "ReqnConceptAlternative") {
		result  << "description" << "ownedComment" << "priority" << "source" << "type";
	}
	else if (element == "ReqnFeatured") {
		result  << "description" << "ownedComment" << "priority" << "source" << "type";
	}
	else if (element == "ReqnLeaf") {
		result  << "description" << "ownedComment" << "priority" << "source" << "type";
	}
	else if (element == "ReqnParent") {
		result  << "description" << "ownedComment" << "priority" << "source" << "type";
	}
	else if (element == "ReqnParentAlternative") {
		result  << "description" << "ownedComment" << "priority" << "source" << "type";
	}
	else if (element == "ReqnParentMandatory") {
		result  << "description" << "ownedComment" << "priority" << "source" << "type";
	}
	else if (element == "ReqnParentOpAlternative") {
		result  << "description" << "ownedComment" << "priority" << "source" << "type";
	}
	else if (element == "ReqnParentOptional") {
		result  << "description" << "ownedComment" << "priority" << "source" << "type";
	}
	else if (element == "ReqnParentOr") {
		result  << "description" << "ownedComment" << "priority" << "source" << "type";
	}
	return result;
}

QStringList RequirementsMetamodelPlugin::getPortTypes(QString const &/*diagram*/, QString const &element) const
{
	QStringList result;
	if (element == "Comment") {
		result << "NonTyped";
	}
	else if (element == "RequirementsDiagramNode") {
		result << "NonTyped";
	}
	else if (element == "ReqnConceptAlternative") {
		result << "NonTyped";
	}
	else if (element == "ReqnFeatured") {
		result << "NonTyped";
	}
	else if (element == "ReqnLeaf") {
		result << "NonTyped";
	}
	else if (element == "ReqnParent") {
		result << "NonTyped";
	}
	else if (element == "ReqnParentAlternative") {
		result << "NonTyped";
	}
	else if (element == "ReqnParentMandatory") {
		result << "NonTyped";
	}
	else if (element == "ReqnParentOpAlternative") {
		result << "NonTyped";
	}
	else if (element == "ReqnParentOptional") {
		result << "NonTyped";
	}
	else if (element == "ReqnParentOr") {
		result << "NonTyped";
	}
	return result;
}

QStringList RequirementsMetamodelPlugin::getReferenceProperties(QString const &/*diagram*/, QString const &element) const
{
	QStringList result;
	if (element == "Comment") {
	}
	else if (element == "CommentLink") {
	}
	else if (element == "RequirementsDiagramNode") {
	}
	else if (element == "ReqeP2N") {
	}
	else if (element == "ReqnConceptAlternative") {
	}
	else if (element == "ReqnFeatured") {
	}
	else if (element == "ReqnLeaf") {
	}
	else if (element == "ReqnParent") {
	}
	else if (element == "ReqnParentAlternative") {
	}
	else if (element == "ReqnParentMandatory") {
	}
	else if (element == "ReqnParentOpAlternative") {
	}
	else if (element == "ReqnParentOptional") {
	}
	else if (element == "ReqnParentOr") {
	}
	return result;
}

QStringList RequirementsMetamodelPlugin::getTypesContainedBy(QString const &element) const
{
	QStringList result;
	if (element == "RequirementsDiagramNode") {
		result << "ReqnFeatured" << "ReqnConceptAlternative" << "ReqnLeaf" << "ReqnParent" << "ReqnParentMandatory" << "ReqnParentOr" << "ReqnParentOptional" << "ReqnParentAlternative" << "ReqeP2N" ;
	}
	return result;
}

QList<QPair<QPair<QString,QString>,QPair<bool,QString> > > RequirementsMetamodelPlugin::getPossibleEdges(QString const &element) const
{
	QList<QPair<QPair<QString,QString>,QPair<bool,QString> > > result;
	Q_UNUSED(element);
	return result;
}

//(-1) means "edge", (+1) means "node"
int RequirementsMetamodelPlugin::isNodeOrEdge(QString const &element) const
{
	if (element == "Comment")
		return 1;
	else if (element == "CommentLink")
		return -1;
	else if (element == "RequirementsDiagramNode")
		return 1;
	else if (element == "ReqeP2N")
		return -1;
	else if (element == "ReqnConceptAlternative")
		return 1;
	else if (element == "ReqnFeatured")
		return 1;
	else if (element == "ReqnLeaf")
		return 1;
	else if (element == "ReqnParent")
		return 1;
	else if (element == "ReqnParentAlternative")
		return 1;
	else if (element == "ReqnParentMandatory")
		return 1;
	else if (element == "ReqnParentOpAlternative")
		return 1;
	else if (element == "ReqnParentOptional")
		return 1;
	else if (element == "ReqnParentOr")
		return 1;
	else if (element == "ReqnPriority")
		return 0;
	else if (element == "ReqnType")
		return 0;
	return 0;
}
QString RequirementsMetamodelPlugin::getGroupsXML() const 
{
	return QString::fromUtf8("");
}

QStringList RequirementsMetamodelPlugin::getEnumValues(QString name) const 
{
	QStringList result;
	if (name == "ReqnPriority")
		result << QString::fromUtf8("High") << QString::fromUtf8("Medium") << QString::fromUtf8("Low") << QString::fromUtf8("NA");
	else if (name == "ParameterDirectionKind")
		result << QString::fromUtf8("in") << QString::fromUtf8("inout") << QString::fromUtf8("out") << QString::fromUtf8("return");
	else if (name == "ReqnType")
		result << QString::fromUtf8("Feature") << QString::fromUtf8("UseCase") << QString::fromUtf8("Supplementary") << QString::fromUtf8("Behaviour");
	else if (name == "AggregationKind")
		result << QString::fromUtf8("none") << QString::fromUtf8("shared") << QString::fromUtf8("composite");
	else if (name == "VisibilityKind")
		result << QString::fromUtf8("private") << QString::fromUtf8("protected") << QString::fromUtf8("public") << QString::fromUtf8("package");
	else if (name == "Bool")
		result << QString::fromUtf8("false") << QString::fromUtf8("true");
	return result;
}

QString RequirementsMetamodelPlugin::getPropertyType(QString const &element, QString const &property) const
{
	return mPropertyTypes[element][property];
}

QString RequirementsMetamodelPlugin::getPropertyDefaultValue(QString const &element, QString const &property) const
{
	return mPropertyDefault[element][property];
}

QList<qReal::ListenerInterface*> RequirementsMetamodelPlugin::listeners() const
{
	QList<qReal::ListenerInterface*> result;
	return result;
}
