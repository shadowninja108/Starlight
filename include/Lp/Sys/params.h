#pragma once

#include "types.h"
#include "sead/string.h"
#include "sead/runtime.h"
#include "sead/hash.h"
#include "sead/stream.h"
#include "sead/print.h"
#include "Lp/Utl.h"
#include "iusehionode.h"

namespace Lp {

  namespace Sys {
      class Params;

      class ParamNode : public Lp::Sys::IUseHioNode {
        public:
          u64 ParamNode_x8;
          char *mParamName;
          Lp::Sys::ParamNode *mNextChild;
          Lp::Sys::Params *mParent;
          u32 mFlags;

        virtual ~ParamNode();
        virtual void* checkDerivedRuntimeTypeInfo(sead::RuntimeTypeInfo::Interface const*); // unknown return type
        virtual void* getRuntimeTypeInfo(); // unknown return type
        virtual void* free_();  // unknown return type
        virtual void addToParent(Lp::Sys::Params*);
        virtual void removeFromParent();
        virtual void addToParent_(Lp::Sys::Params*);
        virtual void removeFromParent_();
        virtual void unknown1() = 0;
        virtual void unknown2() = 0;
        virtual void key(sead::BufferedSafeStringBase<char>*);
        virtual void valueHash_(sead::HashCRC32::Context *);
        virtual void label(sead::BufferedSafeStringBase<char> *);
        virtual void meta(sead::BufferedSafeStringBase<char> *);
        virtual bool isEqual(Lp::Sys::ParamNode const&) = 0;
        virtual void copy(Lp::Sys::ParamNode const&) = 0;
        virtual void lerp(Lp::Sys::ParamNode const&,Lp::Sys::ParamNode const&,float) = 0;
        virtual void onApply();
        virtual void readByaml(Lp::Utl::ByamlIter &,int);
        virtual void writeByaml(Lp::Utl::ByamlWriter &,int);
        virtual void writeYaml(Lp::Utl::YamlWriter &,int);
        virtual void readStream(sead::ReadStream &);
        virtual void writeStream(sead::WriteStream &);
        virtual void formatPrint_(char const*,sead::PrintOutput *);
      };

      class Params : public ParamNode {
        public:
        Lp::Sys::ParamNode *previousChild;
        
        virtual void unknown1();
        virtual void unknown2();

        virtual bool isEqual(Lp::Sys::ParamNode const&);
        virtual void copy(Lp::Sys::ParamNode const&);
        virtual void lerp(Lp::Sys::ParamNode const&,Lp::Sys::ParamNode const&,float);

        virtual void pathName(sead::BufferedSafeStringBase<char> *);
        virtual char* extName();
        virtual bool makePathName(sead::BufferedSafeStringBase<char> *,bool);
        virtual unsigned int getSaveTmpBufferSize(); // somewhat of a guess on return type
        virtual void save(sead::SafeStringBase<char> const&);
        virtual bool load(sead::SafeStringBase<char> const&);
        virtual void convertTool_(sead::SafeStringBase<char> const&);
        virtual void commit_(sead::SafeStringBase<char> const&);
        virtual bool isYamlArray_();
        virtual void readByaml_(Lp::Utl::ByamlIter &);
        virtual void writeByaml_(Lp::Utl::ByamlWriter &);
        virtual void writeYaml_(Lp::Utl::YamlWriter &);
        virtual void pushBackChild(Lp::Sys::ParamNode *);
        virtual void removedChildPos_(Lp::Sys::ParamNode *,Lp::Sys::ParamNode *);
      };



      template<class T>
      class Param : ParamNode {
        public:
        T mRef;

        virtual void unknown1();
        virtual void unknown2();
        
        virtual bool isEqual(Lp::Sys::ParamNode const&);
        virtual void copy(Lp::Sys::ParamNode const&);
        virtual void lerp(Lp::Sys::ParamNode const&,Lp::Sys::ParamNode const&,float);

        virtual int typeId();
        virtual char* typeName();
        virtual T* ref_();
        virtual bool operator==(Lp::Sys::Param<T> const &);
        virtual bool operator!=(Lp::Sys::Param<T> const &);
        virtual bool operator==(T const &);
        virtual bool operator!=(T const &);
        virtual bool isEqual_(T const&);
        virtual void writeStream_Label(sead::WriteStream &);
      };
  };
};