// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: protoId.proto

#include "protoId.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

//begin custom modify
#if defined(_MSC_VER)
#pragma warning(disable:4125)
#endif // _MSC_VER
//end custom modify
namespace msg {
}  // namespace msg
namespace protobuf_protoId_2eproto {
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[2];
const ::google::protobuf::uint32 TableStruct::offsets[1] = {};
static const ::google::protobuf::internal::MigrationSchema* schemas = NULL;
static const ::google::protobuf::Message* const* file_default_instances = NULL;

void protobuf_AssignDescriptors() {
  AddDescriptors();
  ::google::protobuf::MessageFactory* factory = NULL;
  AssignDescriptors(
      "protoId.proto", schemas, file_default_instances, TableStruct::offsets, factory,
      NULL, file_level_enum_descriptors, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\rprotoId.proto\022\003msg*\233\001\n\007ProtoId\022\021\n\rRegi"
      "sterReqId\020\000\022\021\n\rRegisterRspId\020\001\022\016\n\nLoginR"
      "eqId\020\002\022\016\n\nLoginRspId\020\003\022\016\n\nMatchReqId\020\004\022\016"
      "\n\nMatchRspId\020\005\022\024\n\020MatchCancelReqId\020\006\022\024\n\020"
      "MatchCancelRspId\020\007*\030\n\nOptionType\022\n\n\006Move"
      "Id\020\000b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 212);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "protoId.proto", &protobuf_RegisterTypes);
}

void AddDescriptors() {
  static GOOGLE_PROTOBUF_DECLARE_ONCE(once);
  ::google::protobuf::GoogleOnceInit(&once, &AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_protoId_2eproto
namespace msg {
const ::google::protobuf::EnumDescriptor* ProtoId_descriptor() {
  protobuf_protoId_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_protoId_2eproto::file_level_enum_descriptors[0];
}
bool ProtoId_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
      return true;
    default:
      return false;
  }
}

const ::google::protobuf::EnumDescriptor* OptionType_descriptor() {
  protobuf_protoId_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_protoId_2eproto::file_level_enum_descriptors[1];
}
bool OptionType_IsValid(int value) {
  switch (value) {
    case 0:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace msg

// @@protoc_insertion_point(global_scope)
