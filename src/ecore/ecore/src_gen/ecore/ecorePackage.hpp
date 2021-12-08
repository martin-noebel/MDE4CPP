//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef ECOREPACKAGE_HPP
#define ECOREPACKAGE_HPP

// namespace macro header include
#include "ecore/ecore.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EParameter;
	class EDataType;
	class EStringToStringMapEntry;
	class EGenericType;
	class EReference;
	class ETypeParameter;
	class EOperation;
	class EAttribute;
	class EAnnotation;
	class EClass;
}

namespace ecore 
{
	class EAnnotation;
	class EAttribute;
	class EClass;
	class EClassifier;
	class EDataType;
	class EEnum;
	class EEnumLiteral;
	class EFactory;
	class EGenericType;
	class EModelElement;
	class ENamedElement;
	class EObject;
	class EObjectContainer;
	class EOperation;
	class EPackage;
	class EParameter;
	class EReference;
	class EStringToStringMapEntry;
	class EStructuralFeature;
	class ETypeParameter;
	class ETypedElement;
}
 
namespace ecore 
{
	/*!
	The Metamodel Package for the ecore metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class ECORE_API ecorePackage : virtual public EPackage 
	{
		private:    
			ecorePackage(ecorePackage const&) = delete;
			ecorePackage& operator=(ecorePackage const&) = delete;

		protected:
			ecorePackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			// Begin Class EAnnotation
			//Class and Feature IDs 
			static const long long EANNOTATION_CLASS = 1746034582;
			static const unsigned int EANNOTATION_CLASS_FEATURE_COUNT = 9;
			static const unsigned int EANNOTATION_CLASS_OPERATION_COUNT = 16;
			static const long long EANNOTATION_ATTRIBUTE_DETAILS = 2073689448;
			static const long long EANNOTATION_ATTRIBUTE_SOURCE = 1359708608;
			
			static const long long EANNOTATION_ATTRIBUTE_CONTENTS = 2082751101;
			static const long long EANNOTATION_ATTRIBUTE_EMODELELEMENT = 1240803737;
			static const long long EANNOTATION_ATTRIBUTE_REFERENCES = 1415075333;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEAnnotation_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getEAnnotation_Attribute_details() const = 0;
			virtual std::shared_ptr<ecore::EAttribute> getEAnnotation_Attribute_source() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getEAnnotation_Attribute_contents() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEAnnotation_Attribute_eModelElement() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEAnnotation_Attribute_references() const = 0;
			
			
			// End Class EAnnotation


			// Begin Class EAttribute
			//Class and Feature IDs 
			static const long long EATTRIBUTE_CLASS = 1433133167;
			static const unsigned int EATTRIBUTE_CLASS_FEATURE_COUNT = 24;
			static const unsigned int EATTRIBUTE_CLASS_OPERATION_COUNT = 17;
			static const long long EATTRIBUTE_ATTRIBUTE_ID = 219304985;
			
			static const long long EATTRIBUTE_ATTRIBUTE_EATTRIBUTETYPE = 1114798654;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEAttribute_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getEAttribute_Attribute_iD() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getEAttribute_Attribute_eAttributeType() const = 0;
			
			
			// End Class EAttribute


			// Begin Class EClass
			//Class and Feature IDs 
			static const long long ECLASS_CLASS = 625132329;
			static const unsigned int ECLASS_CLASS_FEATURE_COUNT = 27;
			static const unsigned int ECLASS_CLASS_OPERATION_COUNT = 28;
			static const long long ECLASS_ATTRIBUTE_ABSTRACT = 1145425837;
			static const long long ECLASS_ATTRIBUTE_INTERFACE = 1017848326;
			
			static const long long ECLASS_ATTRIBUTE_EALLATTRIBUTES = 1563144507;
			static const long long ECLASS_ATTRIBUTE_EALLCONTAINMENTS = 2003804802;
			static const long long ECLASS_ATTRIBUTE_EALLGENERICSUPERTYPES = 715028471;
			static const long long ECLASS_ATTRIBUTE_EALLOPERATIONS = 1655327643;
			static const long long ECLASS_ATTRIBUTE_EALLREFERENCES = 234180456;
			static const long long ECLASS_ATTRIBUTE_EALLSTRUCTURALFEATURES = 251658674;
			static const long long ECLASS_ATTRIBUTE_EALLSUPERTYPES = 722286883;
			static const long long ECLASS_ATTRIBUTE_EATTRIBUTES = 1968665068;
			static const long long ECLASS_ATTRIBUTE_EGENERICSUPERTYPES = 1788136135;
			static const long long ECLASS_ATTRIBUTE_EIDATTRIBUTE = 286112893;
			static const long long ECLASS_ATTRIBUTE_EOPERATIONS = 2018646751;
			static const long long ECLASS_ATTRIBUTE_EREFERENCES = 312227431;
			static const long long ECLASS_ATTRIBUTE_ESTRUCTURALFEATURES = 760542545;
			static const long long ECLASS_ATTRIBUTE_ESUPERTYPES = 305494445;
			
			static const int ECLASS_OPERATION_GETEOPERATION_EINT = 1526673885;
			static const int ECLASS_OPERATION_GETESTRUCTURALFEATURE_EINT = 1143915648;
			static const int ECLASS_OPERATION_GETESTRUCTURALFEATURE_ESTRING = 927658850;
			static const int ECLASS_OPERATION_GETFEATURECOUNT = 663421227;
			static const int ECLASS_OPERATION_GETFEATUREID_ESTRUCTURALFEATURE = 118348729;
			static const int ECLASS_OPERATION_GETFEATURETYPE_ESTRUCTURALFEATURE = 1392350498;
			static const int ECLASS_OPERATION_GETOPERATIONCOUNT = 2008923785;
			static const int ECLASS_OPERATION_GETOPERATIONID_EOPERATION = 88181657;
			static const int ECLASS_OPERATION_GETOVERRIDE_EOPERATION = 280340408;
			static const int ECLASS_OPERATION_ISSUPERTYPEOF_ECLASS = 253558657;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEClass_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getEClass_Attribute_abstract() const = 0;
			virtual std::shared_ptr<ecore::EAttribute> getEClass_Attribute_interface() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eAllAttributes() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eAllContainments() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eAllGenericSuperTypes() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eAllOperations() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eAllReferences() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eAllStructuralFeatures() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eAllSuperTypes() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eAttributes() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eGenericSuperTypes() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eIDAttribute() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eOperations() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eReferences() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eStructuralFeatures() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEClass_Attribute_eSuperTypes() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getEClass_Operation_getEOperation_EInt() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEClass_Operation_getEStructuralFeature_EInt() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEClass_Operation_getEStructuralFeature_EString() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEClass_Operation_getFeatureCount() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEClass_Operation_getFeatureID_EStructuralFeature() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEClass_Operation_getFeatureType_EStructuralFeature() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEClass_Operation_getOperationCount() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEClass_Operation_getOperationID_EOperation() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEClass_Operation_getOverride_EOperation() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEClass_Operation_isSuperTypeOf_EClass() const = 0;
			
			// End Class EClass


			// Begin Class EClassifier
			//Class and Feature IDs 
			static const long long ECLASSIFIER_CLASS = 198601986;
			static const unsigned int ECLASSIFIER_CLASS_FEATURE_COUNT = 11;
			static const unsigned int ECLASSIFIER_CLASS_OPERATION_COUNT = 18;
			static const long long ECLASSIFIER_ATTRIBUTE_DEFAULTVALUE = 708511813;
			static const long long ECLASSIFIER_ATTRIBUTE_INSTANCECLASS = 1507267760;
			static const long long ECLASSIFIER_ATTRIBUTE_INSTANCECLASSNAME = 498308604;
			static const long long ECLASSIFIER_ATTRIBUTE_INSTANCETYPENAME = 91166420;
			
			static const long long ECLASSIFIER_ATTRIBUTE_EPACKAGE = 667668406;
			static const long long ECLASSIFIER_ATTRIBUTE_ETYPEPARAMETERS = 180939705;
			
			static const int ECLASSIFIER_OPERATION_GETCLASSIFIERID = 1232310610;
			static const int ECLASSIFIER_OPERATION_ISINSTANCE_EJAVAOBJECT = 890144981;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEClassifier_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getEClassifier_Attribute_defaultValue() const = 0;
			virtual std::shared_ptr<ecore::EAttribute> getEClassifier_Attribute_instanceClass() const = 0;
			virtual std::shared_ptr<ecore::EAttribute> getEClassifier_Attribute_instanceClassName() const = 0;
			virtual std::shared_ptr<ecore::EAttribute> getEClassifier_Attribute_instanceTypeName() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getEClassifier_Attribute_ePackage() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEClassifier_Attribute_eTypeParameters() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getEClassifier_Operation_getClassifierID() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEClassifier_Operation_isInstance_EJavaObject() const = 0;
			
			// End Class EClassifier


			// Begin Class EDataType
			//Class and Feature IDs 
			static const long long EDATATYPE_CLASS = 1778684692;
			static const unsigned int EDATATYPE_CLASS_FEATURE_COUNT = 12;
			static const unsigned int EDATATYPE_CLASS_OPERATION_COUNT = 18;
			static const long long EDATATYPE_ATTRIBUTE_SERIALIZABLE = 1834291525;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEDataType_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getEDataType_Attribute_serializable() const = 0;
			
			
			
			// End Class EDataType


			// Begin Class EEnum
			//Class and Feature IDs 
			static const long long EENUM_CLASS = 789245707;
			static const unsigned int EENUM_CLASS_FEATURE_COUNT = 13;
			static const unsigned int EENUM_CLASS_OPERATION_COUNT = 21;
			
			static const long long EENUM_ATTRIBUTE_ELITERALS = 383347513;
			
			static const int EENUM_OPERATION_GETEENUMLITERAL_ESTRING = 1917703622;
			static const int EENUM_OPERATION_GETEENUMLITERAL_EINT = 1070395435;
			static const int EENUM_OPERATION_GETEENUMLITERALBYLITERAL_ESTRING = 582537382;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEEnum_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getEEnum_Attribute_eLiterals() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getEEnum_Operation_getEEnumLiteral_EString() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEEnum_Operation_getEEnumLiteral_EInt() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEEnum_Operation_getEEnumLiteralByLiteral_EString() const = 0;
			
			// End Class EEnum


			// Begin Class EEnumLiteral
			//Class and Feature IDs 
			static const long long EENUMLITERAL_CLASS = 306949309;
			static const unsigned int EENUMLITERAL_CLASS_FEATURE_COUNT = 9;
			static const unsigned int EENUMLITERAL_CLASS_OPERATION_COUNT = 16;
			static const long long EENUMLITERAL_ATTRIBUTE_INSTANCE = 187888184;
			static const long long EENUMLITERAL_ATTRIBUTE_LITERAL = 1440466420;
			static const long long EENUMLITERAL_ATTRIBUTE_VALUE = 62470530;
			
			static const long long EENUMLITERAL_ATTRIBUTE_EENUM = 915129413;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEEnumLiteral_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getEEnumLiteral_Attribute_instance() const = 0;
			virtual std::shared_ptr<ecore::EAttribute> getEEnumLiteral_Attribute_literal() const = 0;
			virtual std::shared_ptr<ecore::EAttribute> getEEnumLiteral_Attribute_value() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getEEnumLiteral_Attribute_eEnum() const = 0;
			
			
			// End Class EEnumLiteral


			// Begin Class EFactory
			//Class and Feature IDs 
			static const long long EFACTORY_CLASS = 817046646;
			static const unsigned int EFACTORY_CLASS_FEATURE_COUNT = 5;
			static const unsigned int EFACTORY_CLASS_OPERATION_COUNT = 19;
			
			static const long long EFACTORY_ATTRIBUTE_EPACKAGE = 1068195627;
			
			static const int EFACTORY_OPERATION_CONVERTTOSTRING_EDATATYPE_EJAVAOBJECT = 776190528;
			static const int EFACTORY_OPERATION_CREATE_ECLASS = 2062111577;
			static const int EFACTORY_OPERATION_CREATEFROMSTRING_EDATATYPE_ESTRING = 1793041850;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEFactory_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getEFactory_Attribute_ePackage() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getEFactory_Operation_convertToString_EDataType_EJavaObject() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEFactory_Operation_create_EClass() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEFactory_Operation_createFromString_EDataType_EString() const = 0;
			
			// End Class EFactory


			// Begin Class EGenericType
			//Class and Feature IDs 
			static const long long EGENERICTYPE_CLASS = 1282018195;
			static const unsigned int EGENERICTYPE_CLASS_FEATURE_COUNT = 6;
			static const unsigned int EGENERICTYPE_CLASS_OPERATION_COUNT = 1;
			
			static const long long EGENERICTYPE_ATTRIBUTE_ECLASSIFIER = 764574639;
			static const long long EGENERICTYPE_ATTRIBUTE_ELOWERBOUND = 73662213;
			static const long long EGENERICTYPE_ATTRIBUTE_ERAWTYPE = 168573994;
			static const long long EGENERICTYPE_ATTRIBUTE_ETYPEARGUMENTS = 1891170551;
			static const long long EGENERICTYPE_ATTRIBUTE_ETYPEPARAMETER = 55930959;
			static const long long EGENERICTYPE_ATTRIBUTE_EUPPERBOUND = 849919749;
			
			static const int EGENERICTYPE_OPERATION_ISINSTANCE_EJAVAOBJECT = 1426574931;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEGenericType_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getEGenericType_Attribute_eClassifier() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEGenericType_Attribute_eLowerBound() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEGenericType_Attribute_eRawType() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEGenericType_Attribute_eTypeArguments() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEGenericType_Attribute_eTypeParameter() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEGenericType_Attribute_eUpperBound() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getEGenericType_Operation_isInstance_EJavaObject() const = 0;
			
			// End Class EGenericType


			// Begin Class EModelElement
			//Class and Feature IDs 
			static const long long EMODELELEMENT_CLASS = 1193165779;
			static const unsigned int EMODELELEMENT_CLASS_FEATURE_COUNT = 4;
			static const unsigned int EMODELELEMENT_CLASS_OPERATION_COUNT = 16;
			
			static const long long EMODELELEMENT_ATTRIBUTE_EANNOTATIONS = 936038724;
			
			static const int EMODELELEMENT_OPERATION_GETEANNOTATION_ESTRING = 304921690;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEModelElement_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getEModelElement_Attribute_eAnnotations() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getEModelElement_Operation_getEAnnotation_EString() const = 0;
			
			// End Class EModelElement


			// Begin Class ENamedElement
			//Class and Feature IDs 
			static const long long ENAMEDELEMENT_CLASS = 2138707061;
			static const unsigned int ENAMEDELEMENT_CLASS_FEATURE_COUNT = 5;
			static const unsigned int ENAMEDELEMENT_CLASS_OPERATION_COUNT = 16;
			static const long long ENAMEDELEMENT_ATTRIBUTE_NAME = 83783545;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getENamedElement_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getENamedElement_Attribute_name() const = 0;
			
			
			
			// End Class ENamedElement


			// Begin Class EObject
			//Class and Feature IDs 
			static const long long EOBJECT_CLASS = 2051543432;
			static const unsigned int EOBJECT_CLASS_FEATURE_COUNT = 3;
			static const unsigned int EOBJECT_CLASS_OPERATION_COUNT = 15;
			static const long long EOBJECT_ATTRIBUTE_METAELEMENTID = 434534114;
			
			static const long long EOBJECT_ATTRIBUTE_ECONTAINER = 1415346592;
			static const long long EOBJECT_ATTRIBUTE_ECONTENTUNION = 607674888;
			
			static const int EOBJECT_OPERATION_EALLCONTENTS = 345308248;
			static const int EOBJECT_OPERATION_ECLASS = 1897829605;
			static const int EOBJECT_OPERATION_ECONTAINER = 1564505762;
			static const int EOBJECT_OPERATION_ECONTAININGFEATURE = 1314774326;
			static const int EOBJECT_OPERATION_ECONTAINMENTFEATURE = 1559436300;
			static const int EOBJECT_OPERATION_ECONTENTS = 1140157049;
			static const int EOBJECT_OPERATION_ECROSSREFERENCES = 1830400680;
			static const int EOBJECT_OPERATION_EGET_ESTRUCTURALFEATURE = 765237638;
			static const int EOBJECT_OPERATION_EGET_ESTRUCTURALFEATURE_EBOOLEAN = 728807147;
			static const int EOBJECT_OPERATION_EINVOKE_EOPERATION_EELIST = 447398534;
			static const int EOBJECT_OPERATION_EISPROXY = 780766387;
			static const int EOBJECT_OPERATION_EISSET_ESTRUCTURALFEATURE = 527097480;
			static const int EOBJECT_OPERATION_ERESOURCE = 281242010;
			static const int EOBJECT_OPERATION_ESET_ESTRUCTURALFEATURE_EJAVAOBJECT = 921412853;
			static const int EOBJECT_OPERATION_EUNSET_ESTRUCTURALFEATURE = 640572767;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEObject_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getEObject_Attribute_metaElementID() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getEObject_Attribute_eContainer() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEObject_Attribute_eContentUnion() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eAllContents() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eClass() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eContainer() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eContainingFeature() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eContainmentFeature() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eContents() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eCrossReferences() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eGet_EStructuralFeature() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eGet_EStructuralFeature_EBoolean() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eInvoke_EOperation_EEList() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eIsProxy() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eIsSet_EStructuralFeature() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eResource() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eSet_EStructuralFeature_EJavaObject() const = 0;
			virtual std::shared_ptr<ecore::EOperation> getEObject_Operation_eUnset_EStructuralFeature() const = 0;
			
			// End Class EObject


			// Begin Class EObjectContainer
			//Class and Feature IDs 
			static const long long EOBJECTCONTAINER_CLASS = 2040922192;
			static const unsigned int EOBJECTCONTAINER_CLASS_FEATURE_COUNT = 4;
			static const unsigned int EOBJECTCONTAINER_CLASS_OPERATION_COUNT = 15;
			
			static const long long EOBJECTCONTAINER_ATTRIBUTE_CONTAINER = 642035704;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEObjectContainer_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getEObjectContainer_Attribute_container() const = 0;
			
			
			// End Class EObjectContainer


			// Begin Class EOperation
			//Class and Feature IDs 
			static const long long EOPERATION_CLASS = 1293372482;
			static const unsigned int EOPERATION_CLASS_FEATURE_COUNT = 19;
			static const unsigned int EOPERATION_CLASS_OPERATION_COUNT = 17;
			static const long long EOPERATION_ATTRIBUTE_OPERATIONID = 73146206;
			
			static const long long EOPERATION_ATTRIBUTE_ECONTAININGCLASS = 1004783888;
			static const long long EOPERATION_ATTRIBUTE_EEXCEPTIONS = 2137090473;
			static const long long EOPERATION_ATTRIBUTE_EGENERICEXCEPTIONS = 1213307460;
			static const long long EOPERATION_ATTRIBUTE_EPARAMETERS = 571447580;
			static const long long EOPERATION_ATTRIBUTE_ETYPEPARAMETERS = 604223722;
			
			static const int EOPERATION_OPERATION_ISOVERRIDEOF_EOPERATION = 861941010;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEOperation_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getEOperation_Attribute_operationID() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getEOperation_Attribute_eContainingClass() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEOperation_Attribute_eExceptions() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEOperation_Attribute_eGenericExceptions() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEOperation_Attribute_eParameters() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEOperation_Attribute_eTypeParameters() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getEOperation_Operation_isOverrideOf_EOperation() const = 0;
			
			// End Class EOperation


			// Begin Class EPackage
			//Class and Feature IDs 
			static const long long EPACKAGE_CLASS = 1953920355;
			static const unsigned int EPACKAGE_CLASS_FEATURE_COUNT = 11;
			static const unsigned int EPACKAGE_CLASS_OPERATION_COUNT = 17;
			static const long long EPACKAGE_ATTRIBUTE_NSPREFIX = 241047441;
			static const long long EPACKAGE_ATTRIBUTE_NSURI = 1725243795;
			
			static const long long EPACKAGE_ATTRIBUTE_ECLASSIFIERS = 1345983723;
			static const long long EPACKAGE_ATTRIBUTE_EFACTORYINSTANCE = 592531188;
			static const long long EPACKAGE_ATTRIBUTE_ESUBPACKAGES = 1385963497;
			static const long long EPACKAGE_ATTRIBUTE_ESUPERPACKAGE = 475850303;
			
			static const int EPACKAGE_OPERATION_GETECLASSIFIER_ESTRING = 1732523502;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEPackage_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getEPackage_Attribute_nsPrefix() const = 0;
			virtual std::shared_ptr<ecore::EAttribute> getEPackage_Attribute_nsURI() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getEPackage_Attribute_eClassifiers() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEPackage_Attribute_eFactoryInstance() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEPackage_Attribute_eSubpackages() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEPackage_Attribute_eSuperPackage() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getEPackage_Operation_getEClassifier_EString() const = 0;
			
			// End Class EPackage


			// Begin Class EParameter
			//Class and Feature IDs 
			static const long long EPARAMETER_CLASS = 461177325;
			static const unsigned int EPARAMETER_CLASS_FEATURE_COUNT = 14;
			static const unsigned int EPARAMETER_CLASS_OPERATION_COUNT = 16;
			
			static const long long EPARAMETER_ATTRIBUTE_EOPERATION = 1004679149;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEParameter_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getEParameter_Attribute_eOperation() const = 0;
			
			
			// End Class EParameter


			// Begin Class EReference
			//Class and Feature IDs 
			static const long long EREFERENCE_CLASS = 390204639;
			static const unsigned int EREFERENCE_CLASS_FEATURE_COUNT = 28;
			static const unsigned int EREFERENCE_CLASS_OPERATION_COUNT = 17;
			static const long long EREFERENCE_ATTRIBUTE_CONTAINER = 1262215369;
			static const long long EREFERENCE_ATTRIBUTE_CONTAINMENT = 32998926;
			static const long long EREFERENCE_ATTRIBUTE_RESOLVEPROXIES = 1460441940;
			
			static const long long EREFERENCE_ATTRIBUTE_EKEYS = 323132827;
			static const long long EREFERENCE_ATTRIBUTE_EOPPOSITE = 1161094411;
			static const long long EREFERENCE_ATTRIBUTE_EREFERENCETYPE = 503735774;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEReference_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getEReference_Attribute_container() const = 0;
			virtual std::shared_ptr<ecore::EAttribute> getEReference_Attribute_containment() const = 0;
			virtual std::shared_ptr<ecore::EAttribute> getEReference_Attribute_resolveProxies() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getEReference_Attribute_eKeys() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEReference_Attribute_eOpposite() const = 0;
			virtual std::shared_ptr<ecore::EReference> getEReference_Attribute_eReferenceType() const = 0;
			
			
			// End Class EReference


			// Begin Class EStringToStringMapEntry
			//Class and Feature IDs 
			static const long long ESTRINGTOSTRINGMAPENTRY_CLASS = 1101973251;
			static const unsigned int ESTRINGTOSTRINGMAPENTRY_CLASS_FEATURE_COUNT = 2;
			static const unsigned int ESTRINGTOSTRINGMAPENTRY_CLASS_OPERATION_COUNT = 0;
			static const long long ESTRINGTOSTRINGMAPENTRY_ATTRIBUTE_KEY = 45004349;
			static const long long ESTRINGTOSTRINGMAPENTRY_ATTRIBUTE_VALUE = 954398054;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEStringToStringMapEntry_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getEStringToStringMapEntry_Attribute_key() const = 0;
			virtual std::shared_ptr<ecore::EAttribute> getEStringToStringMapEntry_Attribute_value() const = 0;
			
			
			
			// End Class EStringToStringMapEntry


			// Begin Class EStructuralFeature
			//Class and Feature IDs 
			static const long long ESTRUCTURALFEATURE_CLASS = 1432739060;
			static const unsigned int ESTRUCTURALFEATURE_CLASS_FEATURE_COUNT = 22;
			static const unsigned int ESTRUCTURALFEATURE_CLASS_OPERATION_COUNT = 17;
			static const long long ESTRUCTURALFEATURE_ATTRIBUTE_CHANGEABLE = 1341891071;
			static const long long ESTRUCTURALFEATURE_ATTRIBUTE_DEFAULTVALUE = 1964634655;
			static const long long ESTRUCTURALFEATURE_ATTRIBUTE_DEFAULTVALUELITERAL = 1510573111;
			static const long long ESTRUCTURALFEATURE_ATTRIBUTE_DERIVED = 22840792;
			static const long long ESTRUCTURALFEATURE_ATTRIBUTE_FEATUREID = 1239846016;
			static const long long ESTRUCTURALFEATURE_ATTRIBUTE_TRANSIENT = 762367195;
			static const long long ESTRUCTURALFEATURE_ATTRIBUTE_UNSETTABLE = 1513353825;
			static const long long ESTRUCTURALFEATURE_ATTRIBUTE_VOLATILE = 1237609455;
			
			static const long long ESTRUCTURALFEATURE_ATTRIBUTE_ECONTAININGCLASS = 755827049;
			
			static const int ESTRUCTURALFEATURE_OPERATION_GETCONTAINERCLASS = 172675706;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getEStructuralFeature_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getEStructuralFeature_Attribute_changeable() const = 0;
			virtual std::shared_ptr<ecore::EAttribute> getEStructuralFeature_Attribute_defaultValue() const = 0;
			virtual std::shared_ptr<ecore::EAttribute> getEStructuralFeature_Attribute_defaultValueLiteral() const = 0;
			virtual std::shared_ptr<ecore::EAttribute> getEStructuralFeature_Attribute_derived() const = 0;
			virtual std::shared_ptr<ecore::EAttribute> getEStructuralFeature_Attribute_featureID() const = 0;
			virtual std::shared_ptr<ecore::EAttribute> getEStructuralFeature_Attribute_transient() const = 0;
			virtual std::shared_ptr<ecore::EAttribute> getEStructuralFeature_Attribute_unsettable() const = 0;
			virtual std::shared_ptr<ecore::EAttribute> getEStructuralFeature_Attribute_volatile() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getEStructuralFeature_Attribute_eContainingClass() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getEStructuralFeature_Operation_getContainerClass() const = 0;
			
			// End Class EStructuralFeature


			// Begin Class ETypeParameter
			//Class and Feature IDs 
			static const long long ETYPEPARAMETER_CLASS = 1516033880;
			static const unsigned int ETYPEPARAMETER_CLASS_FEATURE_COUNT = 6;
			static const unsigned int ETYPEPARAMETER_CLASS_OPERATION_COUNT = 16;
			
			static const long long ETYPEPARAMETER_ATTRIBUTE_EBOUNDS = 1856035957;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getETypeParameter_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getETypeParameter_Attribute_eBounds() const = 0;
			
			
			// End Class ETypeParameter


			// Begin Class ETypedElement
			//Class and Feature IDs 
			static const long long ETYPEDELEMENT_CLASS = 714923840;
			static const unsigned int ETYPEDELEMENT_CLASS_FEATURE_COUNT = 13;
			static const unsigned int ETYPEDELEMENT_CLASS_OPERATION_COUNT = 16;
			static const long long ETYPEDELEMENT_ATTRIBUTE_LOWERBOUND = 890711000;
			static const long long ETYPEDELEMENT_ATTRIBUTE_MANY = 1205122658;
			static const long long ETYPEDELEMENT_ATTRIBUTE_ORDERED = 958020308;
			static const long long ETYPEDELEMENT_ATTRIBUTE_REQUIRED = 1521094122;
			static const long long ETYPEDELEMENT_ATTRIBUTE_UNIQUE = 981671803;
			static const long long ETYPEDELEMENT_ATTRIBUTE_UPPERBOUND = 1666968536;
			
			static const long long ETYPEDELEMENT_ATTRIBUTE_EGENERICTYPE = 1266326300;
			static const long long ETYPEDELEMENT_ATTRIBUTE_ETYPE = 775612694;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getETypedElement_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getETypedElement_Attribute_lowerBound() const = 0;
			virtual std::shared_ptr<ecore::EAttribute> getETypedElement_Attribute_many() const = 0;
			virtual std::shared_ptr<ecore::EAttribute> getETypedElement_Attribute_ordered() const = 0;
			virtual std::shared_ptr<ecore::EAttribute> getETypedElement_Attribute_required() const = 0;
			virtual std::shared_ptr<ecore::EAttribute> getETypedElement_Attribute_unique() const = 0;
			virtual std::shared_ptr<ecore::EAttribute> getETypedElement_Attribute_upperBound() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getETypedElement_Attribute_eGenericType() const = 0;
			virtual std::shared_ptr<ecore::EReference> getETypedElement_Attribute_eType() const = 0;
			
			
			// End Class ETypedElement

			static const int EBIGDECIMAL_CLASS = 3;
			static const int EBIGINTEGER_CLASS = 4;
			static const int EBOOLEAN_CLASS = 5;
			static const int EBOOLEANOBJECT_CLASS = 6;
			static const int EBYTE_CLASS = 7;
			static const int EBYTEARRAY_CLASS = 8;
			static const int EBYTEOBJECT_CLASS = 9;
			static const int ECHAR_CLASS = 10;
			static const int ECHARACTEROBJECT_CLASS = 11;
			static const int EDATE_CLASS = 15;
			static const int EDIAGNOSTICCHAIN_CLASS = 16;
			static const int EDOUBLE_CLASS = 17;
			static const int EDOUBLEOBJECT_CLASS = 18;
			static const int EELIST_CLASS = 19;
			static const int EENUMERATOR_CLASS = 22;
			static const int EFEATUREMAP_CLASS = 24;
			static const int EFEATUREMAPENTRY_CLASS = 25;
			static const int EFLOAT_CLASS = 26;
			static const int EFLOATOBJECT_CLASS = 27;
			static const int EINT_CLASS = 29;
			static const int EINTEGEROBJECT_CLASS = 30;
			static const int EINVOCATIONTARGETEXCEPTION_CLASS = 31;
			static const int EJAVACLASS_CLASS = 32;
			static const int EJAVAOBJECT_CLASS = 33;
			static const int ELONG_CLASS = 34;
			static const int ELONGOBJECT_CLASS = 35;
			static const int EMAP_CLASS = 36;
			static const int ERESOURCE_CLASS = 45;
			static const int ERESOURCESET_CLASS = 46;
			static const int ESHORT_CLASS = 47;
			static const int ESHORTOBJECT_CLASS = 48;
			static const int ESTRING_CLASS = 49;
			static const int ETREEITERATOR_CLASS = 52;
			
			virtual std::shared_ptr<ecore::EDataType> getEBigDecimal_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEBigInteger_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEBoolean_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEBooleanObject_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEByte_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEByteArray_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEByteObject_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEChar_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getECharacterObject_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEDate_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEDiagnosticChain_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEDouble_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEDoubleObject_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEEList_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEEnumerator_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEFeatureMap_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEFeatureMapEntry_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEFloat_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEFloatObject_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEInt_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEIntegerObject_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEInvocationTargetException_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEJavaClass_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEJavaObject_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getELong_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getELongObject_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEMap_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEResource_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEResourceSet_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEShort_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEShortObject_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getEString_Class() const = 0;
			virtual std::shared_ptr<ecore::EDataType> getETreeIterator_Class() const = 0;
			

			

			//Singleton Instance and Getter
			private:
				static std::shared_ptr<ecorePackage> instance;
			public:
				static std::shared_ptr<ecorePackage> eInstance();

			//prevent from hiding functions
			using EPackage::getEAnnotation;
			using EPackage::getEClassifier;
	};
}
#endif /* end of include guard: ECOREPACKAGE_HPP */
