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
  static const ::google::protobuf::internal::ParseTable schema[5];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsFrameImpl();
void InitDefaultsFrame();
void InitDefaultsOptionEventImpl();
void InitDefaultsOptionEvent();
void InitDefaultsFrameOptsImpl();
void InitDefaultsFrameOpts();
void InitDefaultsLogicFrameImpl();
void InitDefaultsLogicFrame();
void InitDefaultsNextFrameOptsImpl();
void InitDefaultsNextFrameOpts();
inline void InitDefaults() {
  InitDefaultsFrame();
  InitDefaultsOptionEvent();
  InitDefaultsFrameOpts();
  InitDefaultsLogicFrame();
  InitDefaultsNextFrameOpts();
}
}  // namespace protobuf_game_2eproto
namespace msg {
class Frame;
class FrameDefaultTypeInternal;
extern FrameDefaultTypeInternal _Frame_default_instance_;
class FrameOpts;
class FrameOptsDefaultTypeInternal;
extern FrameOptsDefaultTypeInternal _FrameOpts_default_instance_;
class LogicFrame;
class LogicFrameDefaultTypeInternal;
extern LogicFrameDefaultTypeInternal _LogicFrame_default_instance_;
class NextFrameOpts;
class NextFrameOptsDefaultTypeInternal;
extern NextFrameOptsDefaultTypeInternal _NextFrameOpts_default_instance_;
class OptionEvent;
class OptionEventDefaultTypeInternal;
extern OptionEventDefaultTypeInternal _OptionEvent_default_instance_;
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
// -------------------------------------------------------------------

class OptionEvent : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:msg.OptionEvent) */ {
 public:
  OptionEvent();
  virtual ~OptionEvent();

  OptionEvent(const OptionEvent& from);

  inline OptionEvent& operator=(const OptionEvent& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  OptionEvent(OptionEvent&& from) noexcept
    : OptionEvent() {
    *this = ::std::move(from);
  }

  inline OptionEvent& operator=(OptionEvent&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const OptionEvent& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const OptionEvent* internal_default_instance() {
    return reinterpret_cast<const OptionEvent*>(
               &_OptionEvent_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(OptionEvent* other);
  friend void swap(OptionEvent& a, OptionEvent& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline OptionEvent* New() const PROTOBUF_FINAL { return New(NULL); }

  OptionEvent* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const OptionEvent& from);
  void MergeFrom(const OptionEvent& from);
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
  void InternalSwap(OptionEvent* other);
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

  // int32 playerId = 1;
  void clear_playerid();
  static const int kPlayerIdFieldNumber = 1;
  ::google::protobuf::int32 playerid() const;
  void set_playerid(::google::protobuf::int32 value);

  // int32 optType = 2;
  void clear_opttype();
  static const int kOptTypeFieldNumber = 2;
  ::google::protobuf::int32 opttype() const;
  void set_opttype(::google::protobuf::int32 value);

  // float eastValue = 3;
  void clear_eastvalue();
  static const int kEastValueFieldNumber = 3;
  float eastvalue() const;
  void set_eastvalue(float value);

  // float northValue = 4;
  void clear_northvalue();
  static const int kNorthValueFieldNumber = 4;
  float northvalue() const;
  void set_northvalue(float value);

  // float charRotattion = 5;
  void clear_charrotattion();
  static const int kCharRotattionFieldNumber = 5;
  float charrotattion() const;
  void set_charrotattion(float value);

  // @@protoc_insertion_point(class_scope:msg.OptionEvent)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int32 playerid_;
  ::google::protobuf::int32 opttype_;
  float eastvalue_;
  float northvalue_;
  float charrotattion_;
  mutable int _cached_size_;
  friend struct ::protobuf_game_2eproto::TableStruct;
  friend void ::protobuf_game_2eproto::InitDefaultsOptionEventImpl();
};
// -------------------------------------------------------------------

class FrameOpts : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:msg.FrameOpts) */ {
 public:
  FrameOpts();
  virtual ~FrameOpts();

  FrameOpts(const FrameOpts& from);

  inline FrameOpts& operator=(const FrameOpts& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  FrameOpts(FrameOpts&& from) noexcept
    : FrameOpts() {
    *this = ::std::move(from);
  }

  inline FrameOpts& operator=(FrameOpts&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const FrameOpts& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const FrameOpts* internal_default_instance() {
    return reinterpret_cast<const FrameOpts*>(
               &_FrameOpts_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    2;

  void Swap(FrameOpts* other);
  friend void swap(FrameOpts& a, FrameOpts& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline FrameOpts* New() const PROTOBUF_FINAL { return New(NULL); }

  FrameOpts* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const FrameOpts& from);
  void MergeFrom(const FrameOpts& from);
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
  void InternalSwap(FrameOpts* other);
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

  // repeated .msg.OptionEvent opts = 2;
  int opts_size() const;
  void clear_opts();
  static const int kOptsFieldNumber = 2;
  const ::msg::OptionEvent& opts(int index) const;
  ::msg::OptionEvent* mutable_opts(int index);
  ::msg::OptionEvent* add_opts();
  ::google::protobuf::RepeatedPtrField< ::msg::OptionEvent >*
      mutable_opts();
  const ::google::protobuf::RepeatedPtrField< ::msg::OptionEvent >&
      opts() const;

  // int32 frameId = 1;
  void clear_frameid();
  static const int kFrameIdFieldNumber = 1;
  ::google::protobuf::int32 frameid() const;
  void set_frameid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:msg.FrameOpts)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::msg::OptionEvent > opts_;
  ::google::protobuf::int32 frameid_;
  mutable int _cached_size_;
  friend struct ::protobuf_game_2eproto::TableStruct;
  friend void ::protobuf_game_2eproto::InitDefaultsFrameOptsImpl();
};
// -------------------------------------------------------------------

class LogicFrame : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:msg.LogicFrame) */ {
 public:
  LogicFrame();
  virtual ~LogicFrame();

  LogicFrame(const LogicFrame& from);

  inline LogicFrame& operator=(const LogicFrame& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  LogicFrame(LogicFrame&& from) noexcept
    : LogicFrame() {
    *this = ::std::move(from);
  }

  inline LogicFrame& operator=(LogicFrame&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const LogicFrame& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const LogicFrame* internal_default_instance() {
    return reinterpret_cast<const LogicFrame*>(
               &_LogicFrame_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    3;

  void Swap(LogicFrame* other);
  friend void swap(LogicFrame& a, LogicFrame& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline LogicFrame* New() const PROTOBUF_FINAL { return New(NULL); }

  LogicFrame* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const LogicFrame& from);
  void MergeFrom(const LogicFrame& from);
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
  void InternalSwap(LogicFrame* other);
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

  // repeated .msg.FrameOpts unsyncFrames = 2;
  int unsyncframes_size() const;
  void clear_unsyncframes();
  static const int kUnsyncFramesFieldNumber = 2;
  const ::msg::FrameOpts& unsyncframes(int index) const;
  ::msg::FrameOpts* mutable_unsyncframes(int index);
  ::msg::FrameOpts* add_unsyncframes();
  ::google::protobuf::RepeatedPtrField< ::msg::FrameOpts >*
      mutable_unsyncframes();
  const ::google::protobuf::RepeatedPtrField< ::msg::FrameOpts >&
      unsyncframes() const;

  // int32 frameId = 1;
  void clear_frameid();
  static const int kFrameIdFieldNumber = 1;
  ::google::protobuf::int32 frameid() const;
  void set_frameid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:msg.LogicFrame)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::msg::FrameOpts > unsyncframes_;
  ::google::protobuf::int32 frameid_;
  mutable int _cached_size_;
  friend struct ::protobuf_game_2eproto::TableStruct;
  friend void ::protobuf_game_2eproto::InitDefaultsLogicFrameImpl();
};
// -------------------------------------------------------------------

class NextFrameOpts : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:msg.NextFrameOpts) */ {
 public:
  NextFrameOpts();
  virtual ~NextFrameOpts();

  NextFrameOpts(const NextFrameOpts& from);

  inline NextFrameOpts& operator=(const NextFrameOpts& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  NextFrameOpts(NextFrameOpts&& from) noexcept
    : NextFrameOpts() {
    *this = ::std::move(from);
  }

  inline NextFrameOpts& operator=(NextFrameOpts&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const NextFrameOpts& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const NextFrameOpts* internal_default_instance() {
    return reinterpret_cast<const NextFrameOpts*>(
               &_NextFrameOpts_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    4;

  void Swap(NextFrameOpts* other);
  friend void swap(NextFrameOpts& a, NextFrameOpts& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline NextFrameOpts* New() const PROTOBUF_FINAL { return New(NULL); }

  NextFrameOpts* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const NextFrameOpts& from);
  void MergeFrom(const NextFrameOpts& from);
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
  void InternalSwap(NextFrameOpts* other);
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

  // repeated .msg.OptionEvent opts = 4;
  int opts_size() const;
  void clear_opts();
  static const int kOptsFieldNumber = 4;
  const ::msg::OptionEvent& opts(int index) const;
  ::msg::OptionEvent* mutable_opts(int index);
  ::msg::OptionEvent* add_opts();
  ::google::protobuf::RepeatedPtrField< ::msg::OptionEvent >*
      mutable_opts();
  const ::google::protobuf::RepeatedPtrField< ::msg::OptionEvent >&
      opts() const;

  // int32 frameId = 1;
  void clear_frameid();
  static const int kFrameIdFieldNumber = 1;
  ::google::protobuf::int32 frameid() const;
  void set_frameid(::google::protobuf::int32 value);

  // int32 roomId = 2;
  void clear_roomid();
  static const int kRoomIdFieldNumber = 2;
  ::google::protobuf::int32 roomid() const;
  void set_roomid(::google::protobuf::int32 value);

  // int32 playerId = 3;
  void clear_playerid();
  static const int kPlayerIdFieldNumber = 3;
  ::google::protobuf::int32 playerid() const;
  void set_playerid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:msg.NextFrameOpts)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::msg::OptionEvent > opts_;
  ::google::protobuf::int32 frameid_;
  ::google::protobuf::int32 roomid_;
  ::google::protobuf::int32 playerid_;
  mutable int _cached_size_;
  friend struct ::protobuf_game_2eproto::TableStruct;
  friend void ::protobuf_game_2eproto::InitDefaultsNextFrameOptsImpl();
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

// -------------------------------------------------------------------

// OptionEvent

// int32 playerId = 1;
inline void OptionEvent::clear_playerid() {
  playerid_ = 0;
}
inline ::google::protobuf::int32 OptionEvent::playerid() const {
  // @@protoc_insertion_point(field_get:msg.OptionEvent.playerId)
  return playerid_;
}
inline void OptionEvent::set_playerid(::google::protobuf::int32 value) {
  
  playerid_ = value;
  // @@protoc_insertion_point(field_set:msg.OptionEvent.playerId)
}

// int32 optType = 2;
inline void OptionEvent::clear_opttype() {
  opttype_ = 0;
}
inline ::google::protobuf::int32 OptionEvent::opttype() const {
  // @@protoc_insertion_point(field_get:msg.OptionEvent.optType)
  return opttype_;
}
inline void OptionEvent::set_opttype(::google::protobuf::int32 value) {
  
  opttype_ = value;
  // @@protoc_insertion_point(field_set:msg.OptionEvent.optType)
}

// float eastValue = 3;
inline void OptionEvent::clear_eastvalue() {
  eastvalue_ = 0;
}
inline float OptionEvent::eastvalue() const {
  // @@protoc_insertion_point(field_get:msg.OptionEvent.eastValue)
  return eastvalue_;
}
inline void OptionEvent::set_eastvalue(float value) {
  
  eastvalue_ = value;
  // @@protoc_insertion_point(field_set:msg.OptionEvent.eastValue)
}

// float northValue = 4;
inline void OptionEvent::clear_northvalue() {
  northvalue_ = 0;
}
inline float OptionEvent::northvalue() const {
  // @@protoc_insertion_point(field_get:msg.OptionEvent.northValue)
  return northvalue_;
}
inline void OptionEvent::set_northvalue(float value) {
  
  northvalue_ = value;
  // @@protoc_insertion_point(field_set:msg.OptionEvent.northValue)
}

// float charRotattion = 5;
inline void OptionEvent::clear_charrotattion() {
  charrotattion_ = 0;
}
inline float OptionEvent::charrotattion() const {
  // @@protoc_insertion_point(field_get:msg.OptionEvent.charRotattion)
  return charrotattion_;
}
inline void OptionEvent::set_charrotattion(float value) {
  
  charrotattion_ = value;
  // @@protoc_insertion_point(field_set:msg.OptionEvent.charRotattion)
}

// -------------------------------------------------------------------

// FrameOpts

// int32 frameId = 1;
inline void FrameOpts::clear_frameid() {
  frameid_ = 0;
}
inline ::google::protobuf::int32 FrameOpts::frameid() const {
  // @@protoc_insertion_point(field_get:msg.FrameOpts.frameId)
  return frameid_;
}
inline void FrameOpts::set_frameid(::google::protobuf::int32 value) {
  
  frameid_ = value;
  // @@protoc_insertion_point(field_set:msg.FrameOpts.frameId)
}

// repeated .msg.OptionEvent opts = 2;
inline int FrameOpts::opts_size() const {
  return opts_.size();
}
inline void FrameOpts::clear_opts() {
  opts_.Clear();
}
inline const ::msg::OptionEvent& FrameOpts::opts(int index) const {
  // @@protoc_insertion_point(field_get:msg.FrameOpts.opts)
  return opts_.Get(index);
}
inline ::msg::OptionEvent* FrameOpts::mutable_opts(int index) {
  // @@protoc_insertion_point(field_mutable:msg.FrameOpts.opts)
  return opts_.Mutable(index);
}
inline ::msg::OptionEvent* FrameOpts::add_opts() {
  // @@protoc_insertion_point(field_add:msg.FrameOpts.opts)
  return opts_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::msg::OptionEvent >*
FrameOpts::mutable_opts() {
  // @@protoc_insertion_point(field_mutable_list:msg.FrameOpts.opts)
  return &opts_;
}
inline const ::google::protobuf::RepeatedPtrField< ::msg::OptionEvent >&
FrameOpts::opts() const {
  // @@protoc_insertion_point(field_list:msg.FrameOpts.opts)
  return opts_;
}

// -------------------------------------------------------------------

// LogicFrame

// int32 frameId = 1;
inline void LogicFrame::clear_frameid() {
  frameid_ = 0;
}
inline ::google::protobuf::int32 LogicFrame::frameid() const {
  // @@protoc_insertion_point(field_get:msg.LogicFrame.frameId)
  return frameid_;
}
inline void LogicFrame::set_frameid(::google::protobuf::int32 value) {
  
  frameid_ = value;
  // @@protoc_insertion_point(field_set:msg.LogicFrame.frameId)
}

// repeated .msg.FrameOpts unsyncFrames = 2;
inline int LogicFrame::unsyncframes_size() const {
  return unsyncframes_.size();
}
inline void LogicFrame::clear_unsyncframes() {
  unsyncframes_.Clear();
}
inline const ::msg::FrameOpts& LogicFrame::unsyncframes(int index) const {
  // @@protoc_insertion_point(field_get:msg.LogicFrame.unsyncFrames)
  return unsyncframes_.Get(index);
}
inline ::msg::FrameOpts* LogicFrame::mutable_unsyncframes(int index) {
  // @@protoc_insertion_point(field_mutable:msg.LogicFrame.unsyncFrames)
  return unsyncframes_.Mutable(index);
}
inline ::msg::FrameOpts* LogicFrame::add_unsyncframes() {
  // @@protoc_insertion_point(field_add:msg.LogicFrame.unsyncFrames)
  return unsyncframes_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::msg::FrameOpts >*
LogicFrame::mutable_unsyncframes() {
  // @@protoc_insertion_point(field_mutable_list:msg.LogicFrame.unsyncFrames)
  return &unsyncframes_;
}
inline const ::google::protobuf::RepeatedPtrField< ::msg::FrameOpts >&
LogicFrame::unsyncframes() const {
  // @@protoc_insertion_point(field_list:msg.LogicFrame.unsyncFrames)
  return unsyncframes_;
}

// -------------------------------------------------------------------

// NextFrameOpts

// int32 frameId = 1;
inline void NextFrameOpts::clear_frameid() {
  frameid_ = 0;
}
inline ::google::protobuf::int32 NextFrameOpts::frameid() const {
  // @@protoc_insertion_point(field_get:msg.NextFrameOpts.frameId)
  return frameid_;
}
inline void NextFrameOpts::set_frameid(::google::protobuf::int32 value) {
  
  frameid_ = value;
  // @@protoc_insertion_point(field_set:msg.NextFrameOpts.frameId)
}

// int32 roomId = 2;
inline void NextFrameOpts::clear_roomid() {
  roomid_ = 0;
}
inline ::google::protobuf::int32 NextFrameOpts::roomid() const {
  // @@protoc_insertion_point(field_get:msg.NextFrameOpts.roomId)
  return roomid_;
}
inline void NextFrameOpts::set_roomid(::google::protobuf::int32 value) {
  
  roomid_ = value;
  // @@protoc_insertion_point(field_set:msg.NextFrameOpts.roomId)
}

// int32 playerId = 3;
inline void NextFrameOpts::clear_playerid() {
  playerid_ = 0;
}
inline ::google::protobuf::int32 NextFrameOpts::playerid() const {
  // @@protoc_insertion_point(field_get:msg.NextFrameOpts.playerId)
  return playerid_;
}
inline void NextFrameOpts::set_playerid(::google::protobuf::int32 value) {
  
  playerid_ = value;
  // @@protoc_insertion_point(field_set:msg.NextFrameOpts.playerId)
}

// repeated .msg.OptionEvent opts = 4;
inline int NextFrameOpts::opts_size() const {
  return opts_.size();
}
inline void NextFrameOpts::clear_opts() {
  opts_.Clear();
}
inline const ::msg::OptionEvent& NextFrameOpts::opts(int index) const {
  // @@protoc_insertion_point(field_get:msg.NextFrameOpts.opts)
  return opts_.Get(index);
}
inline ::msg::OptionEvent* NextFrameOpts::mutable_opts(int index) {
  // @@protoc_insertion_point(field_mutable:msg.NextFrameOpts.opts)
  return opts_.Mutable(index);
}
inline ::msg::OptionEvent* NextFrameOpts::add_opts() {
  // @@protoc_insertion_point(field_add:msg.NextFrameOpts.opts)
  return opts_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::msg::OptionEvent >*
NextFrameOpts::mutable_opts() {
  // @@protoc_insertion_point(field_mutable_list:msg.NextFrameOpts.opts)
  return &opts_;
}
inline const ::google::protobuf::RepeatedPtrField< ::msg::OptionEvent >&
NextFrameOpts::opts() const {
  // @@protoc_insertion_point(field_list:msg.NextFrameOpts.opts)
  return opts_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace msg

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_game_2eproto__INCLUDED
