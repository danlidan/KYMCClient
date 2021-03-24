// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: game.proto

#ifndef PROTOBUF_game_2eproto__INCLUDED
#define PROTOBUF_game_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protobuf_game_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsFrameImpl();
void InitDefaultsFrame();
inline void InitDefaults() {
  InitDefaultsFrame();
}
}  // namespace protobuf_game_2eproto
namespace msg {
class Frame;
class FrameDefaultTypeInternal;
extern FrameDefaultTypeInternal _Frame_default_instance_;
}  // namespace msg
namespace msg {

// ===================================================================

class Frame : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:msg.Frame) */ {
 public:
  Frame();
  virtual ~Frame();

  Frame(const Frame& from);

  inline Frame& operator=(const Frame& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Frame(Frame&& from) noexcept
    : Frame() {
    *this = ::std::move(from);
  }

  inline Frame& operator=(Frame&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Frame& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Frame* internal_default_instance() {
    return reinterpret_cast<const Frame*>(
               &_Frame_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(Frame* other);
  friend void swap(Frame& a, Frame& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Frame* New() const PROTOBUF_FINAL { return New(NULL); }

  Frame* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const Frame& from);
  void MergeFrom(const Frame& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(Frame* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string testInfo = 1;
  void clear_testinfo();
  static const int kTestInfoFieldNumber = 1;
  const ::std::string& testinfo() const;
  void set_testinfo(const ::std::string& value);
  #if LANG_CXX11
  void set_testinfo(::std::string&& value);
  #endif
  void set_testinfo(const char* value);
  void set_testinfo(const char* value, size_t size);
  ::std::string* mutable_testinfo();
  ::std::string* release_testinfo();
  void set_allocated_testinfo(::std::string* testinfo);

  // @@protoc_insertion_point(class_scope:msg.Frame)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr testinfo_;
  mutable int _cached_size_;
  friend struct ::protobuf_game_2eproto::TableStruct;
  friend void ::protobuf_game_2eproto::InitDefaultsFrameImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Frame

// string testInfo = 1;
inline void Frame::clear_testinfo() {
  testinfo_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Frame::testinfo() const {
  // @@protoc_insertion_point(field_get:msg.Frame.testInfo)
  return testinfo_.GetNoArena();
}
inline void Frame::set_testinfo(const ::std::string& value) {
  
  testinfo_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:msg.Frame.testInfo)
}
#if LANG_CXX11
inline void Frame::set_testinfo(::std::string&& value) {
  
  testinfo_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:msg.Frame.testInfo)
}
#endif
inline void Frame::set_testinfo(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  testinfo_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:msg.Frame.testInfo)
}
inline void Frame::set_testinfo(const char* value, size_t size) {
  
  testinfo_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:msg.Frame.testInfo)
}
inline ::std::string* Frame::mutable_testinfo() {
  
  // @@protoc_insertion_point(field_mutable:msg.Frame.testInfo)
  return testinfo_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Frame::release_testinfo() {
  // @@protoc_insertion_point(field_release:msg.Frame.testInfo)
  
  return testinfo_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Frame::set_allocated_testinfo(::std::string* testinfo) {
  if (testinfo != NULL) {
    
  } else {
    
  }
  testinfo_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), testinfo);
  // @@protoc_insertion_point(field_set_allocated:msg.Frame.testInfo)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace msg

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_game_2eproto__INCLUDED
