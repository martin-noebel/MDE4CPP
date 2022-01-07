//********************************************************************
//*    
//* Warning: This file was generated by ecore4CPP Generator
//*
//********************************************************************

#ifndef OCL_TYPESPACKAGE_HPP
#define OCL_TYPESPACKAGE_HPP

// namespace macro header include
#include "ocl/ocl.hpp"

#include "ecore/EPackage.hpp"

namespace ecore 
{
	class EParameter;
	class EDataType;
	class EStringToStringMapEntry;
	class EGenericType;
	class EReference;
	class EOperation;
	class EAttribute;
	class EAnnotation;
	class EClass;
}

namespace ocl::Types 
{
	class AnyType;
	class BagType;
	class CollectionType;
	class InvalidType;
	class MessageType;
	class NameTypeBinding;
	class OrderedSetType;
	class SequenceType;
	class SetType;
	class TemplateParameterType;
	class TupleType;
	class VoidType;
}
 
namespace ocl::Types 
{
	/*!
	The Metamodel Package for the Types metamodel. This package is used to enable the reflection of model elements. It contains all model elements
	which were described in an ecore file.
	*/
	
	class OCL_API TypesPackage : virtual public ecore::EPackage 
	{
		private:    
			TypesPackage(TypesPackage const&) = delete;
			TypesPackage& operator=(TypesPackage const&) = delete;

		protected:
			TypesPackage(){}

		public:
			//static variables
			static const std::string eNAME;
			static const std::string eNS_URI;
			static const std::string eNS_PREFIX;

			// Begin Class AnyType
			//Class and Feature IDs 
			static const long long ANYTYPE_CLASS = 1049138756;
			static const unsigned int ANYTYPE_CLASS_FEATURE_COUNT = 8;
			static const unsigned int ANYTYPE_CLASS_OPERATION_COUNT = 3;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getAnyType_Class() const = 0;
			
			
			
			
			// End Class AnyType


			// Begin Class BagType
			//Class and Feature IDs 
			static const long long BAGTYPE_CLASS = 1309276377;
			static const unsigned int BAGTYPE_CLASS_FEATURE_COUNT = 11;
			static const unsigned int BAGTYPE_CLASS_OPERATION_COUNT = 4;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getBagType_Class() const = 0;
			
			
			
			
			// End Class BagType


			// Begin Class CollectionType
			//Class and Feature IDs 
			static const long long COLLECTIONTYPE_CLASS = 1993307753;
			static const unsigned int COLLECTIONTYPE_CLASS_FEATURE_COUNT = 11;
			static const unsigned int COLLECTIONTYPE_CLASS_OPERATION_COUNT = 4;
			
			static const long long COLLECTIONTYPE_ATTRIBUTE_ELEMENTTYPE = 1103684901;
			static const long long COLLECTIONTYPE_ATTRIBUTE_INSTANCE = 983882236;
			
			static const int COLLECTIONTYPE_OPERATION_KINDOF_COLLECTIONTYPE = 1909894118;
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getCollectionType_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getCollectionType_Attribute_elementType() const = 0;
			virtual std::shared_ptr<ecore::EReference> getCollectionType_Attribute_instance() const = 0;
			
			virtual std::shared_ptr<ecore::EOperation> getCollectionType_Operation_kindOf_CollectionType() const = 0;
			
			// End Class CollectionType


			// Begin Class InvalidType
			//Class and Feature IDs 
			static const long long INVALIDTYPE_CLASS = 280656823;
			static const unsigned int INVALIDTYPE_CLASS_FEATURE_COUNT = 8;
			static const unsigned int INVALIDTYPE_CLASS_OPERATION_COUNT = 3;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getInvalidType_Class() const = 0;
			
			
			
			
			// End Class InvalidType


			// Begin Class MessageType
			//Class and Feature IDs 
			static const long long MESSAGETYPE_CLASS = 1381501878;
			static const unsigned int MESSAGETYPE_CLASS_FEATURE_COUNT = 10;
			static const unsigned int MESSAGETYPE_CLASS_OPERATION_COUNT = 3;
			
			static const long long MESSAGETYPE_ATTRIBUTE_REFERREDOPERATION = 424348000;
			static const long long MESSAGETYPE_ATTRIBUTE_REFERREDSIGNAL = 909724812;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getMessageType_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getMessageType_Attribute_referredOperation() const = 0;
			virtual std::shared_ptr<ecore::EReference> getMessageType_Attribute_referredSignal() const = 0;
			
			
			// End Class MessageType


			// Begin Class NameTypeBinding
			//Class and Feature IDs 
			static const long long NAMETYPEBINDING_CLASS = 238682409;
			static const unsigned int NAMETYPEBINDING_CLASS_FEATURE_COUNT = 2;
			static const unsigned int NAMETYPEBINDING_CLASS_OPERATION_COUNT = 0;
			static const long long NAMETYPEBINDING_ATTRIBUTE_NAME = 571906446;
			
			static const long long NAMETYPEBINDING_ATTRIBUTE_TYPE = 535890932;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getNameTypeBinding_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getNameTypeBinding_Attribute_name() const = 0;
			
			virtual std::shared_ptr<ecore::EReference> getNameTypeBinding_Attribute_type() const = 0;
			
			
			// End Class NameTypeBinding


			// Begin Class OrderedSetType
			//Class and Feature IDs 
			static const long long ORDEREDSETTYPE_CLASS = 1790854470;
			static const unsigned int ORDEREDSETTYPE_CLASS_FEATURE_COUNT = 11;
			static const unsigned int ORDEREDSETTYPE_CLASS_OPERATION_COUNT = 4;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getOrderedSetType_Class() const = 0;
			
			
			
			
			// End Class OrderedSetType


			// Begin Class SequenceType
			//Class and Feature IDs 
			static const long long SEQUENCETYPE_CLASS = 68596060;
			static const unsigned int SEQUENCETYPE_CLASS_FEATURE_COUNT = 11;
			static const unsigned int SEQUENCETYPE_CLASS_OPERATION_COUNT = 4;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getSequenceType_Class() const = 0;
			
			
			
			
			// End Class SequenceType


			// Begin Class SetType
			//Class and Feature IDs 
			static const long long SETTYPE_CLASS = 1886550814;
			static const unsigned int SETTYPE_CLASS_FEATURE_COUNT = 11;
			static const unsigned int SETTYPE_CLASS_OPERATION_COUNT = 4;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getSetType_Class() const = 0;
			
			
			
			
			// End Class SetType


			// Begin Class TemplateParameterType
			//Class and Feature IDs 
			static const long long TEMPLATEPARAMETERTYPE_CLASS = 989968086;
			static const unsigned int TEMPLATEPARAMETERTYPE_CLASS_FEATURE_COUNT = 9;
			static const unsigned int TEMPLATEPARAMETERTYPE_CLASS_OPERATION_COUNT = 3;
			static const long long TEMPLATEPARAMETERTYPE_ATTRIBUTE_SPECIFICATION = 1021308629;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getTemplateParameterType_Class() const = 0;
			
			virtual std::shared_ptr<ecore::EAttribute> getTemplateParameterType_Attribute_specification() const = 0;
			
			
			
			// End Class TemplateParameterType


			// Begin Class TupleType
			//Class and Feature IDs 
			static const long long TUPLETYPE_CLASS = 1090531508;
			static const unsigned int TUPLETYPE_CLASS_FEATURE_COUNT = 11;
			static const unsigned int TUPLETYPE_CLASS_OPERATION_COUNT = 3;
			
			static const long long TUPLETYPE_ATTRIBUTE_INSTANCE = 1655280315;
			static const long long TUPLETYPE_ATTRIBUTE_PARTS = 872287659;
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getTupleType_Class() const = 0;
			
			
			virtual std::shared_ptr<ecore::EReference> getTupleType_Attribute_instance() const = 0;
			virtual std::shared_ptr<ecore::EReference> getTupleType_Attribute_parts() const = 0;
			
			
			// End Class TupleType


			// Begin Class VoidType
			//Class and Feature IDs 
			static const long long VOIDTYPE_CLASS = 1092966199;
			static const unsigned int VOIDTYPE_CLASS_FEATURE_COUNT = 8;
			static const unsigned int VOIDTYPE_CLASS_OPERATION_COUNT = 3;
			
			
			
			//Class and Feature Getter
			virtual std::shared_ptr<ecore::EClass> getVoidType_Class() const = 0;
			
			
			
			
			// End Class VoidType

			
			

			

			//Singleton Instance and Getter
			private:
				static std::shared_ptr<TypesPackage> instance;
			public:
				static std::shared_ptr<TypesPackage> eInstance();
	};
}
#endif /* end of include guard: OCL_TYPESPACKAGE_HPP */
