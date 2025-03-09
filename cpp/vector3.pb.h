// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: vector3.proto
// Protobuf C++ Version: 5.29.3

#ifndef vector3_2eproto_2epb_2eh
#define vector3_2eproto_2epb_2eh

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
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_vector3_2eproto

namespace google {
namespace protobuf {
namespace internal {
template <typename T>
::absl::string_view GetAnyMessageName();
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_vector3_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_vector3_2eproto;
namespace kevin {
class Vector3;
struct Vector3DefaultTypeInternal;
extern Vector3DefaultTypeInternal _Vector3_default_instance_;
}  // namespace kevin
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace kevin {

// ===================================================================


// -------------------------------------------------------------------

class Vector3 final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:kevin.Vector3) */ {
 public:
  inline Vector3() : Vector3(nullptr) {}
  ~Vector3() PROTOBUF_FINAL;

#if defined(PROTOBUF_CUSTOM_VTABLE)
  void operator delete(Vector3* msg, std::destroying_delete_t) {
    SharedDtor(*msg);
    ::google::protobuf::internal::SizedDelete(msg, sizeof(Vector3));
  }
#endif

  template <typename = void>
  explicit PROTOBUF_CONSTEXPR Vector3(
      ::google::protobuf::internal::ConstantInitialized);

  inline Vector3(const Vector3& from) : Vector3(nullptr, from) {}
  inline Vector3(Vector3&& from) noexcept
      : Vector3(nullptr, std::move(from)) {}
  inline Vector3& operator=(const Vector3& from) {
    CopyFrom(from);
    return *this;
  }
  inline Vector3& operator=(Vector3&& from) noexcept {
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
  static const Vector3& default_instance() {
    return *internal_default_instance();
  }
  static inline const Vector3* internal_default_instance() {
    return reinterpret_cast<const Vector3*>(
        &_Vector3_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(Vector3& a, Vector3& b) { a.Swap(&b); }
  inline void Swap(Vector3* other) {
    if (other == this) return;
    if (::google::protobuf::internal::CanUseInternalSwap(GetArena(), other->GetArena())) {
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Vector3* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Vector3* New(::google::protobuf::Arena* arena = nullptr) const {
    return ::google::protobuf::Message::DefaultConstruct<Vector3>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const Vector3& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const Vector3& from) { Vector3::MergeImpl(*this, from); }

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
  void InternalSwap(Vector3* other);
 private:
  template <typename T>
  friend ::absl::string_view(
      ::google::protobuf::internal::GetAnyMessageName)();
  static ::absl::string_view FullMessageName() { return "kevin.Vector3"; }

 protected:
  explicit Vector3(::google::protobuf::Arena* arena);
  Vector3(::google::protobuf::Arena* arena, const Vector3& from);
  Vector3(::google::protobuf::Arena* arena, Vector3&& from) noexcept
      : Vector3(arena) {
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
    kXFieldNumber = 1,
    kYFieldNumber = 2,
    kZFieldNumber = 3,
  };
  // double x = 1;
  void clear_x() ;
  double x() const;
  void set_x(double value);

  private:
  double _internal_x() const;
  void _internal_set_x(double value);

  public:
  // double y = 2;
  void clear_y() ;
  double y() const;
  void set_y(double value);

  private:
  double _internal_y() const;
  void _internal_set_y(double value);

  public:
  // double z = 3;
  void clear_z() ;
  double z() const;
  void set_z(double value);

  private:
  double _internal_z() const;
  void _internal_set_z(double value);

  public:
  // @@protoc_insertion_point(class_scope:kevin.Vector3)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      2, 3, 0,
      0, 2>
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
                          const Vector3& from_msg);
    double x_;
    double y_;
    double z_;
    ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_vector3_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// Vector3

// double x = 1;
inline void Vector3::clear_x() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.x_ = 0;
}
inline double Vector3::x() const {
  // @@protoc_insertion_point(field_get:kevin.Vector3.x)
  return _internal_x();
}
inline void Vector3::set_x(double value) {
  _internal_set_x(value);
  // @@protoc_insertion_point(field_set:kevin.Vector3.x)
}
inline double Vector3::_internal_x() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.x_;
}
inline void Vector3::_internal_set_x(double value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.x_ = value;
}

// double y = 2;
inline void Vector3::clear_y() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.y_ = 0;
}
inline double Vector3::y() const {
  // @@protoc_insertion_point(field_get:kevin.Vector3.y)
  return _internal_y();
}
inline void Vector3::set_y(double value) {
  _internal_set_y(value);
  // @@protoc_insertion_point(field_set:kevin.Vector3.y)
}
inline double Vector3::_internal_y() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.y_;
}
inline void Vector3::_internal_set_y(double value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.y_ = value;
}

// double z = 3;
inline void Vector3::clear_z() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.z_ = 0;
}
inline double Vector3::z() const {
  // @@protoc_insertion_point(field_get:kevin.Vector3.z)
  return _internal_z();
}
inline void Vector3::set_z(double value) {
  _internal_set_z(value);
  // @@protoc_insertion_point(field_set:kevin.Vector3.z)
}
inline double Vector3::_internal_z() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.z_;
}
inline void Vector3::_internal_set_z(double value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.z_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace kevin


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // vector3_2eproto_2epb_2eh
