// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: odometry.proto
// Protobuf C++ Version: 5.29.3

#ifndef odometry_2eproto_2epb_2eh
#define odometry_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/runtime_version.h"
#if PROTOBUF_VERSION != 5029003
#error "Protobuf C++ gencode is built with an incompatible version of"
#error "Protobuf C++ headers/runtime. See"
#error "https://protobuf.dev/support/cross-version-runtime-guarantee/#cpp"
#endif
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/message_lite.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
#include "pose.pb.h"
#include "twist.pb.h"
#include "header.pb.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_odometry_2eproto

namespace google {
namespace protobuf {
namespace internal {
template <typename T>
::absl::string_view GetAnyMessageName();
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_odometry_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_odometry_2eproto;
namespace kevin {
class Odometry;
struct OdometryDefaultTypeInternal;
extern OdometryDefaultTypeInternal _Odometry_default_instance_;
}  // namespace kevin
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace kevin {

// ===================================================================


// -------------------------------------------------------------------

class Odometry final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:kevin.Odometry) */ {
 public:
  inline Odometry() : Odometry(nullptr) {}
  ~Odometry() PROTOBUF_FINAL;

#if defined(PROTOBUF_CUSTOM_VTABLE)
  void operator delete(Odometry* msg, std::destroying_delete_t) {
    SharedDtor(*msg);
    ::google::protobuf::internal::SizedDelete(msg, sizeof(Odometry));
  }
#endif

  template <typename = void>
  explicit PROTOBUF_CONSTEXPR Odometry(
      ::google::protobuf::internal::ConstantInitialized);

  inline Odometry(const Odometry& from) : Odometry(nullptr, from) {}
  inline Odometry(Odometry&& from) noexcept
      : Odometry(nullptr, std::move(from)) {}
  inline Odometry& operator=(const Odometry& from) {
    CopyFrom(from);
    return *this;
  }
  inline Odometry& operator=(Odometry&& from) noexcept {
    if (this == &from) return *this;
    if (::google::protobuf::internal::CanMoveWithInternalSwap(GetArena(), from.GetArena())) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Odometry& default_instance() {
    return *internal_default_instance();
  }
  static inline const Odometry* internal_default_instance() {
    return reinterpret_cast<const Odometry*>(
        &_Odometry_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(Odometry& a, Odometry& b) { a.Swap(&b); }
  inline void Swap(Odometry* other) {
    if (other == this) return;
    if (::google::protobuf::internal::CanUseInternalSwap(GetArena(), other->GetArena())) {
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Odometry* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Odometry* New(::google::protobuf::Arena* arena = nullptr) const {
    return ::google::protobuf::Message::DefaultConstruct<Odometry>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const Odometry& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const Odometry& from) { Odometry::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  bool IsInitialized() const {
    return true;
  }
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() PROTOBUF_FINAL;
  #if defined(PROTOBUF_CUSTOM_VTABLE)
  private:
  static ::size_t ByteSizeLong(const ::google::protobuf::MessageLite& msg);
  static ::uint8_t* _InternalSerialize(
      const MessageLite& msg, ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream);

  public:
  ::size_t ByteSizeLong() const { return ByteSizeLong(*this); }
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const {
    return _InternalSerialize(*this, target, stream);
  }
  #else   // PROTOBUF_CUSTOM_VTABLE
  ::size_t ByteSizeLong() const final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  #endif  // PROTOBUF_CUSTOM_VTABLE
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  static void SharedDtor(MessageLite& self);
  void InternalSwap(Odometry* other);
 private:
  template <typename T>
  friend ::absl::string_view(
      ::google::protobuf::internal::GetAnyMessageName)();
  static ::absl::string_view FullMessageName() { return "kevin.Odometry"; }

 protected:
  explicit Odometry(::google::protobuf::Arena* arena);
  Odometry(::google::protobuf::Arena* arena, const Odometry& from);
  Odometry(::google::protobuf::Arena* arena, Odometry&& from) noexcept
      : Odometry(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::internal::ClassData* GetClassData() const PROTOBUF_FINAL;
  static void* PlacementNew_(const void*, void* mem,
                             ::google::protobuf::Arena* arena);
  static constexpr auto InternalNewImpl_();
  static const ::google::protobuf::internal::ClassDataFull _class_data_;

 public:
  ::google::protobuf::Metadata GetMetadata() const;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kChildFrameIdFieldNumber = 2,
    kHeaderFieldNumber = 1,
    kPoseFieldNumber = 3,
    kTwistFieldNumber = 4,
  };
  // string child_frame_id = 2;
  void clear_child_frame_id() ;
  const std::string& child_frame_id() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_child_frame_id(Arg_&& arg, Args_... args);
  std::string* mutable_child_frame_id();
  PROTOBUF_NODISCARD std::string* release_child_frame_id();
  void set_allocated_child_frame_id(std::string* value);

  private:
  const std::string& _internal_child_frame_id() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_child_frame_id(
      const std::string& value);
  std::string* _internal_mutable_child_frame_id();

  public:
  // .kevin.Header header = 1;
  bool has_header() const;
  void clear_header() ;
  const ::kevin::Header& header() const;
  PROTOBUF_NODISCARD ::kevin::Header* release_header();
  ::kevin::Header* mutable_header();
  void set_allocated_header(::kevin::Header* value);
  void unsafe_arena_set_allocated_header(::kevin::Header* value);
  ::kevin::Header* unsafe_arena_release_header();

  private:
  const ::kevin::Header& _internal_header() const;
  ::kevin::Header* _internal_mutable_header();

  public:
  // .kevin.Pose pose = 3;
  bool has_pose() const;
  void clear_pose() ;
  const ::kevin::Pose& pose() const;
  PROTOBUF_NODISCARD ::kevin::Pose* release_pose();
  ::kevin::Pose* mutable_pose();
  void set_allocated_pose(::kevin::Pose* value);
  void unsafe_arena_set_allocated_pose(::kevin::Pose* value);
  ::kevin::Pose* unsafe_arena_release_pose();

  private:
  const ::kevin::Pose& _internal_pose() const;
  ::kevin::Pose* _internal_mutable_pose();

  public:
  // .kevin.Twist twist = 4;
  bool has_twist() const;
  void clear_twist() ;
  const ::kevin::Twist& twist() const;
  PROTOBUF_NODISCARD ::kevin::Twist* release_twist();
  ::kevin::Twist* mutable_twist();
  void set_allocated_twist(::kevin::Twist* value);
  void unsafe_arena_set_allocated_twist(::kevin::Twist* value);
  ::kevin::Twist* unsafe_arena_release_twist();

  private:
  const ::kevin::Twist& _internal_twist() const;
  ::kevin::Twist* _internal_mutable_twist();

  public:
  // @@protoc_insertion_point(class_scope:kevin.Odometry)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      2, 4, 3,
      37, 2>
      _table_;

  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from,
                          const Odometry& from_msg);
    ::google::protobuf::internal::HasBits<1> _has_bits_;
    ::google::protobuf::internal::CachedSize _cached_size_;
    ::google::protobuf::internal::ArenaStringPtr child_frame_id_;
    ::kevin::Header* header_;
    ::kevin::Pose* pose_;
    ::kevin::Twist* twist_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_odometry_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// Odometry

// .kevin.Header header = 1;
inline bool Odometry::has_header() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.header_ != nullptr);
  return value;
}
inline const ::kevin::Header& Odometry::_internal_header() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  const ::kevin::Header* p = _impl_.header_;
  return p != nullptr ? *p : reinterpret_cast<const ::kevin::Header&>(::kevin::_Header_default_instance_);
}
inline const ::kevin::Header& Odometry::header() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:kevin.Odometry.header)
  return _internal_header();
}
inline void Odometry::unsafe_arena_set_allocated_header(::kevin::Header* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.header_);
  }
  _impl_.header_ = reinterpret_cast<::kevin::Header*>(value);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:kevin.Odometry.header)
}
inline ::kevin::Header* Odometry::release_header() {
  ::google::protobuf::internal::TSanWrite(&_impl_);

  _impl_._has_bits_[0] &= ~0x00000001u;
  ::kevin::Header* released = _impl_.header_;
  _impl_.header_ = nullptr;
  if (::google::protobuf::internal::DebugHardenForceCopyInRelease()) {
    auto* old = reinterpret_cast<::google::protobuf::MessageLite*>(released);
    released = ::google::protobuf::internal::DuplicateIfNonNull(released);
    if (GetArena() == nullptr) {
      delete old;
    }
  } else {
    if (GetArena() != nullptr) {
      released = ::google::protobuf::internal::DuplicateIfNonNull(released);
    }
  }
  return released;
}
inline ::kevin::Header* Odometry::unsafe_arena_release_header() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:kevin.Odometry.header)

  _impl_._has_bits_[0] &= ~0x00000001u;
  ::kevin::Header* temp = _impl_.header_;
  _impl_.header_ = nullptr;
  return temp;
}
inline ::kevin::Header* Odometry::_internal_mutable_header() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (_impl_.header_ == nullptr) {
    auto* p = ::google::protobuf::Message::DefaultConstruct<::kevin::Header>(GetArena());
    _impl_.header_ = reinterpret_cast<::kevin::Header*>(p);
  }
  return _impl_.header_;
}
inline ::kevin::Header* Odometry::mutable_header() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  _impl_._has_bits_[0] |= 0x00000001u;
  ::kevin::Header* _msg = _internal_mutable_header();
  // @@protoc_insertion_point(field_mutable:kevin.Odometry.header)
  return _msg;
}
inline void Odometry::set_allocated_header(::kevin::Header* value) {
  ::google::protobuf::Arena* message_arena = GetArena();
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (message_arena == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.header_);
  }

  if (value != nullptr) {
    ::google::protobuf::Arena* submessage_arena = reinterpret_cast<::google::protobuf::MessageLite*>(value)->GetArena();
    if (message_arena != submessage_arena) {
      value = ::google::protobuf::internal::GetOwnedMessage(message_arena, value, submessage_arena);
    }
    _impl_._has_bits_[0] |= 0x00000001u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000001u;
  }

  _impl_.header_ = reinterpret_cast<::kevin::Header*>(value);
  // @@protoc_insertion_point(field_set_allocated:kevin.Odometry.header)
}

// string child_frame_id = 2;
inline void Odometry::clear_child_frame_id() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.child_frame_id_.ClearToEmpty();
}
inline const std::string& Odometry::child_frame_id() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:kevin.Odometry.child_frame_id)
  return _internal_child_frame_id();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void Odometry::set_child_frame_id(Arg_&& arg,
                                                     Args_... args) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.child_frame_id_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:kevin.Odometry.child_frame_id)
}
inline std::string* Odometry::mutable_child_frame_id() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_child_frame_id();
  // @@protoc_insertion_point(field_mutable:kevin.Odometry.child_frame_id)
  return _s;
}
inline const std::string& Odometry::_internal_child_frame_id() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.child_frame_id_.Get();
}
inline void Odometry::_internal_set_child_frame_id(const std::string& value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.child_frame_id_.Set(value, GetArena());
}
inline std::string* Odometry::_internal_mutable_child_frame_id() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  return _impl_.child_frame_id_.Mutable( GetArena());
}
inline std::string* Odometry::release_child_frame_id() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:kevin.Odometry.child_frame_id)
  return _impl_.child_frame_id_.Release();
}
inline void Odometry::set_allocated_child_frame_id(std::string* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.child_frame_id_.SetAllocated(value, GetArena());
  if (::google::protobuf::internal::DebugHardenForceCopyDefaultString() && _impl_.child_frame_id_.IsDefault()) {
    _impl_.child_frame_id_.Set("", GetArena());
  }
  // @@protoc_insertion_point(field_set_allocated:kevin.Odometry.child_frame_id)
}

// .kevin.Pose pose = 3;
inline bool Odometry::has_pose() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.pose_ != nullptr);
  return value;
}
inline const ::kevin::Pose& Odometry::_internal_pose() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  const ::kevin::Pose* p = _impl_.pose_;
  return p != nullptr ? *p : reinterpret_cast<const ::kevin::Pose&>(::kevin::_Pose_default_instance_);
}
inline const ::kevin::Pose& Odometry::pose() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:kevin.Odometry.pose)
  return _internal_pose();
}
inline void Odometry::unsafe_arena_set_allocated_pose(::kevin::Pose* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.pose_);
  }
  _impl_.pose_ = reinterpret_cast<::kevin::Pose*>(value);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:kevin.Odometry.pose)
}
inline ::kevin::Pose* Odometry::release_pose() {
  ::google::protobuf::internal::TSanWrite(&_impl_);

  _impl_._has_bits_[0] &= ~0x00000002u;
  ::kevin::Pose* released = _impl_.pose_;
  _impl_.pose_ = nullptr;
  if (::google::protobuf::internal::DebugHardenForceCopyInRelease()) {
    auto* old = reinterpret_cast<::google::protobuf::MessageLite*>(released);
    released = ::google::protobuf::internal::DuplicateIfNonNull(released);
    if (GetArena() == nullptr) {
      delete old;
    }
  } else {
    if (GetArena() != nullptr) {
      released = ::google::protobuf::internal::DuplicateIfNonNull(released);
    }
  }
  return released;
}
inline ::kevin::Pose* Odometry::unsafe_arena_release_pose() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:kevin.Odometry.pose)

  _impl_._has_bits_[0] &= ~0x00000002u;
  ::kevin::Pose* temp = _impl_.pose_;
  _impl_.pose_ = nullptr;
  return temp;
}
inline ::kevin::Pose* Odometry::_internal_mutable_pose() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (_impl_.pose_ == nullptr) {
    auto* p = ::google::protobuf::Message::DefaultConstruct<::kevin::Pose>(GetArena());
    _impl_.pose_ = reinterpret_cast<::kevin::Pose*>(p);
  }
  return _impl_.pose_;
}
inline ::kevin::Pose* Odometry::mutable_pose() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  _impl_._has_bits_[0] |= 0x00000002u;
  ::kevin::Pose* _msg = _internal_mutable_pose();
  // @@protoc_insertion_point(field_mutable:kevin.Odometry.pose)
  return _msg;
}
inline void Odometry::set_allocated_pose(::kevin::Pose* value) {
  ::google::protobuf::Arena* message_arena = GetArena();
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (message_arena == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.pose_);
  }

  if (value != nullptr) {
    ::google::protobuf::Arena* submessage_arena = reinterpret_cast<::google::protobuf::MessageLite*>(value)->GetArena();
    if (message_arena != submessage_arena) {
      value = ::google::protobuf::internal::GetOwnedMessage(message_arena, value, submessage_arena);
    }
    _impl_._has_bits_[0] |= 0x00000002u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000002u;
  }

  _impl_.pose_ = reinterpret_cast<::kevin::Pose*>(value);
  // @@protoc_insertion_point(field_set_allocated:kevin.Odometry.pose)
}

// .kevin.Twist twist = 4;
inline bool Odometry::has_twist() const {
  bool value = (_impl_._has_bits_[0] & 0x00000004u) != 0;
  PROTOBUF_ASSUME(!value || _impl_.twist_ != nullptr);
  return value;
}
inline const ::kevin::Twist& Odometry::_internal_twist() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  const ::kevin::Twist* p = _impl_.twist_;
  return p != nullptr ? *p : reinterpret_cast<const ::kevin::Twist&>(::kevin::_Twist_default_instance_);
}
inline const ::kevin::Twist& Odometry::twist() const ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:kevin.Odometry.twist)
  return _internal_twist();
}
inline void Odometry::unsafe_arena_set_allocated_twist(::kevin::Twist* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.twist_);
  }
  _impl_.twist_ = reinterpret_cast<::kevin::Twist*>(value);
  if (value != nullptr) {
    _impl_._has_bits_[0] |= 0x00000004u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000004u;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:kevin.Odometry.twist)
}
inline ::kevin::Twist* Odometry::release_twist() {
  ::google::protobuf::internal::TSanWrite(&_impl_);

  _impl_._has_bits_[0] &= ~0x00000004u;
  ::kevin::Twist* released = _impl_.twist_;
  _impl_.twist_ = nullptr;
  if (::google::protobuf::internal::DebugHardenForceCopyInRelease()) {
    auto* old = reinterpret_cast<::google::protobuf::MessageLite*>(released);
    released = ::google::protobuf::internal::DuplicateIfNonNull(released);
    if (GetArena() == nullptr) {
      delete old;
    }
  } else {
    if (GetArena() != nullptr) {
      released = ::google::protobuf::internal::DuplicateIfNonNull(released);
    }
  }
  return released;
}
inline ::kevin::Twist* Odometry::unsafe_arena_release_twist() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:kevin.Odometry.twist)

  _impl_._has_bits_[0] &= ~0x00000004u;
  ::kevin::Twist* temp = _impl_.twist_;
  _impl_.twist_ = nullptr;
  return temp;
}
inline ::kevin::Twist* Odometry::_internal_mutable_twist() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (_impl_.twist_ == nullptr) {
    auto* p = ::google::protobuf::Message::DefaultConstruct<::kevin::Twist>(GetArena());
    _impl_.twist_ = reinterpret_cast<::kevin::Twist*>(p);
  }
  return _impl_.twist_;
}
inline ::kevin::Twist* Odometry::mutable_twist() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  _impl_._has_bits_[0] |= 0x00000004u;
  ::kevin::Twist* _msg = _internal_mutable_twist();
  // @@protoc_insertion_point(field_mutable:kevin.Odometry.twist)
  return _msg;
}
inline void Odometry::set_allocated_twist(::kevin::Twist* value) {
  ::google::protobuf::Arena* message_arena = GetArena();
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (message_arena == nullptr) {
    delete reinterpret_cast<::google::protobuf::MessageLite*>(_impl_.twist_);
  }

  if (value != nullptr) {
    ::google::protobuf::Arena* submessage_arena = reinterpret_cast<::google::protobuf::MessageLite*>(value)->GetArena();
    if (message_arena != submessage_arena) {
      value = ::google::protobuf::internal::GetOwnedMessage(message_arena, value, submessage_arena);
    }
    _impl_._has_bits_[0] |= 0x00000004u;
  } else {
    _impl_._has_bits_[0] &= ~0x00000004u;
  }

  _impl_.twist_ = reinterpret_cast<::kevin::Twist*>(value);
  // @@protoc_insertion_point(field_set_allocated:kevin.Odometry.twist)
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace kevin


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // odometry_2eproto_2epb_2eh
