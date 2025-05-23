// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: kinematic_msgs.proto
// Protobuf C++ Version: 5.29.3

#include "kinematic_msgs.pb.h"

#include <algorithm>
#include <type_traits>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/generated_message_tctable_impl.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace kevin {

inline constexpr JointState::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        name_{},
        position_{},
        velocity_{},
        effort_{},
        header_{nullptr} {}

template <typename>
PROTOBUF_CONSTEXPR JointState::JointState(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(),
#endif  // PROTOBUF_CUSTOM_VTABLE
      _impl_(::_pbi::ConstantInitialized()) {
}
struct JointStateDefaultTypeInternal {
  PROTOBUF_CONSTEXPR JointStateDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~JointStateDefaultTypeInternal() {}
  union {
    JointState _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 JointStateDefaultTypeInternal _JointState_default_instance_;
}  // namespace kevin
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_kinematic_5fmsgs_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_kinematic_5fmsgs_2eproto = nullptr;
const ::uint32_t
    TableStruct_kinematic_5fmsgs_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        PROTOBUF_FIELD_OFFSET(::kevin::JointState, _impl_._has_bits_),
        PROTOBUF_FIELD_OFFSET(::kevin::JointState, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::kevin::JointState, _impl_.header_),
        PROTOBUF_FIELD_OFFSET(::kevin::JointState, _impl_.name_),
        PROTOBUF_FIELD_OFFSET(::kevin::JointState, _impl_.position_),
        PROTOBUF_FIELD_OFFSET(::kevin::JointState, _impl_.velocity_),
        PROTOBUF_FIELD_OFFSET(::kevin::JointState, _impl_.effort_),
        0,
        ~0u,
        ~0u,
        ~0u,
        ~0u,
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, 13, -1, sizeof(::kevin::JointState)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::kevin::_JointState_default_instance_._instance,
};
const char descriptor_table_protodef_kinematic_5fmsgs_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\024kinematic_msgs.proto\022\005kevin\032\023standard_"
    "msgs.proto\"m\n\nJointState\022\035\n\006header\030\001 \001(\013"
    "2\r.kevin.Header\022\014\n\004name\030\002 \003(\t\022\020\n\010positio"
    "n\030\003 \003(\001\022\020\n\010velocity\030\004 \003(\001\022\016\n\006effort\030\005 \003("
    "\001b\006proto3"
};
static const ::_pbi::DescriptorTable* const descriptor_table_kinematic_5fmsgs_2eproto_deps[1] =
    {
        &::descriptor_table_standard_5fmsgs_2eproto,
};
static ::absl::once_flag descriptor_table_kinematic_5fmsgs_2eproto_once;
PROTOBUF_CONSTINIT const ::_pbi::DescriptorTable descriptor_table_kinematic_5fmsgs_2eproto = {
    false,
    false,
    169,
    descriptor_table_protodef_kinematic_5fmsgs_2eproto,
    "kinematic_msgs.proto",
    &descriptor_table_kinematic_5fmsgs_2eproto_once,
    descriptor_table_kinematic_5fmsgs_2eproto_deps,
    1,
    1,
    schemas,
    file_default_instances,
    TableStruct_kinematic_5fmsgs_2eproto::offsets,
    file_level_enum_descriptors_kinematic_5fmsgs_2eproto,
    file_level_service_descriptors_kinematic_5fmsgs_2eproto,
};
namespace kevin {
// ===================================================================

class JointState::_Internal {
 public:
  using HasBits =
      decltype(std::declval<JointState>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
      8 * PROTOBUF_FIELD_OFFSET(JointState, _impl_._has_bits_);
};

void JointState::clear_header() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (_impl_.header_ != nullptr) _impl_.header_->Clear();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
JointState::JointState(::google::protobuf::Arena* arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:kevin.JointState)
}
inline PROTOBUF_NDEBUG_INLINE JointState::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::kevin::JointState& from_msg)
      : _has_bits_{from._has_bits_},
        _cached_size_{0},
        name_{visibility, arena, from.name_},
        position_{visibility, arena, from.position_},
        velocity_{visibility, arena, from.velocity_},
        effort_{visibility, arena, from.effort_} {}

JointState::JointState(
    ::google::protobuf::Arena* arena,
    const JointState& from)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  JointState* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);
  ::uint32_t cached_has_bits = _impl_._has_bits_[0];
  _impl_.header_ = (cached_has_bits & 0x00000001u) ? ::google::protobuf::Message::CopyConstruct<::kevin::Header>(
                              arena, *from._impl_.header_)
                        : nullptr;

  // @@protoc_insertion_point(copy_constructor:kevin.JointState)
}
inline PROTOBUF_NDEBUG_INLINE JointState::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0},
        name_{visibility, arena},
        position_{visibility, arena},
        velocity_{visibility, arena},
        effort_{visibility, arena} {}

inline void JointState::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  _impl_.header_ = {};
}
JointState::~JointState() {
  // @@protoc_insertion_point(destructor:kevin.JointState)
  SharedDtor(*this);
}
inline void JointState::SharedDtor(MessageLite& self) {
  JointState& this_ = static_cast<JointState&>(self);
  this_._internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  ABSL_DCHECK(this_.GetArena() == nullptr);
  delete this_._impl_.header_;
  this_._impl_.~Impl_();
}

inline void* JointState::PlacementNew_(const void*, void* mem,
                                        ::google::protobuf::Arena* arena) {
  return ::new (mem) JointState(arena);
}
constexpr auto JointState::InternalNewImpl_() {
  constexpr auto arena_bits = ::google::protobuf::internal::EncodePlacementArenaOffsets({
      PROTOBUF_FIELD_OFFSET(JointState, _impl_.name_) +
          decltype(JointState::_impl_.name_)::
              InternalGetArenaOffset(
                  ::google::protobuf::Message::internal_visibility()),
      PROTOBUF_FIELD_OFFSET(JointState, _impl_.position_) +
          decltype(JointState::_impl_.position_)::
              InternalGetArenaOffset(
                  ::google::protobuf::Message::internal_visibility()),
      PROTOBUF_FIELD_OFFSET(JointState, _impl_.velocity_) +
          decltype(JointState::_impl_.velocity_)::
              InternalGetArenaOffset(
                  ::google::protobuf::Message::internal_visibility()),
      PROTOBUF_FIELD_OFFSET(JointState, _impl_.effort_) +
          decltype(JointState::_impl_.effort_)::
              InternalGetArenaOffset(
                  ::google::protobuf::Message::internal_visibility()),
  });
  if (arena_bits.has_value()) {
    return ::google::protobuf::internal::MessageCreator::ZeroInit(
        sizeof(JointState), alignof(JointState), *arena_bits);
  } else {
    return ::google::protobuf::internal::MessageCreator(&JointState::PlacementNew_,
                                 sizeof(JointState),
                                 alignof(JointState));
  }
}
PROTOBUF_CONSTINIT
PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::google::protobuf::internal::ClassDataFull JointState::_class_data_ = {
    ::google::protobuf::internal::ClassData{
        &_JointState_default_instance_._instance,
        &_table_.header,
        nullptr,  // OnDemandRegisterArenaDtor
        nullptr,  // IsInitialized
        &JointState::MergeImpl,
        ::google::protobuf::Message::GetNewImpl<JointState>(),
#if defined(PROTOBUF_CUSTOM_VTABLE)
        &JointState::SharedDtor,
        ::google::protobuf::Message::GetClearImpl<JointState>(), &JointState::ByteSizeLong,
            &JointState::_InternalSerialize,
#endif  // PROTOBUF_CUSTOM_VTABLE
        PROTOBUF_FIELD_OFFSET(JointState, _impl_._cached_size_),
        false,
    },
    &JointState::kDescriptorMethods,
    &descriptor_table_kinematic_5fmsgs_2eproto,
    nullptr,  // tracker
};
const ::google::protobuf::internal::ClassData* JointState::GetClassData() const {
  ::google::protobuf::internal::PrefetchToLocalCache(&_class_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_class_data_.tc_table);
  return _class_data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<3, 5, 1, 29, 2> JointState::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(JointState, _impl_._has_bits_),
    0, // no _extensions_
    5, 56,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967264,  // skipmap
    offsetof(decltype(_table_), field_entries),
    5,  // num_field_entries
    1,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    _class_data_.base(),
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::kevin::JointState>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    {::_pbi::TcParser::MiniParse, {}},
    // .kevin.Header header = 1;
    {::_pbi::TcParser::FastMtS1,
     {10, 0, 0, PROTOBUF_FIELD_OFFSET(JointState, _impl_.header_)}},
    // repeated string name = 2;
    {::_pbi::TcParser::FastUR1,
     {18, 63, 0, PROTOBUF_FIELD_OFFSET(JointState, _impl_.name_)}},
    // repeated double position = 3;
    {::_pbi::TcParser::FastF64P1,
     {26, 63, 0, PROTOBUF_FIELD_OFFSET(JointState, _impl_.position_)}},
    // repeated double velocity = 4;
    {::_pbi::TcParser::FastF64P1,
     {34, 63, 0, PROTOBUF_FIELD_OFFSET(JointState, _impl_.velocity_)}},
    // repeated double effort = 5;
    {::_pbi::TcParser::FastF64P1,
     {42, 63, 0, PROTOBUF_FIELD_OFFSET(JointState, _impl_.effort_)}},
    {::_pbi::TcParser::MiniParse, {}},
    {::_pbi::TcParser::MiniParse, {}},
  }}, {{
    65535, 65535
  }}, {{
    // .kevin.Header header = 1;
    {PROTOBUF_FIELD_OFFSET(JointState, _impl_.header_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kMessage | ::_fl::kTvTable)},
    // repeated string name = 2;
    {PROTOBUF_FIELD_OFFSET(JointState, _impl_.name_), -1, 0,
    (0 | ::_fl::kFcRepeated | ::_fl::kUtf8String | ::_fl::kRepSString)},
    // repeated double position = 3;
    {PROTOBUF_FIELD_OFFSET(JointState, _impl_.position_), -1, 0,
    (0 | ::_fl::kFcRepeated | ::_fl::kPackedDouble)},
    // repeated double velocity = 4;
    {PROTOBUF_FIELD_OFFSET(JointState, _impl_.velocity_), -1, 0,
    (0 | ::_fl::kFcRepeated | ::_fl::kPackedDouble)},
    // repeated double effort = 5;
    {PROTOBUF_FIELD_OFFSET(JointState, _impl_.effort_), -1, 0,
    (0 | ::_fl::kFcRepeated | ::_fl::kPackedDouble)},
  }}, {{
    {::_pbi::TcParser::GetTable<::kevin::Header>()},
  }}, {{
    "\20\0\4\0\0\0\0\0"
    "kevin.JointState"
    "name"
  }},
};

PROTOBUF_NOINLINE void JointState::Clear() {
// @@protoc_insertion_point(message_clear_start:kevin.JointState)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.name_.Clear();
  _impl_.position_.Clear();
  _impl_.velocity_.Clear();
  _impl_.effort_.Clear();
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    ABSL_DCHECK(_impl_.header_ != nullptr);
    _impl_.header_->Clear();
  }
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::uint8_t* JointState::_InternalSerialize(
            const MessageLite& base, ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) {
          const JointState& this_ = static_cast<const JointState&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::uint8_t* JointState::_InternalSerialize(
            ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) const {
          const JointState& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(serialize_to_array_start:kevin.JointState)
          ::uint32_t cached_has_bits = 0;
          (void)cached_has_bits;

          cached_has_bits = this_._impl_._has_bits_[0];
          // .kevin.Header header = 1;
          if (cached_has_bits & 0x00000001u) {
            target = ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
                1, *this_._impl_.header_, this_._impl_.header_->GetCachedSize(), target,
                stream);
          }

          // repeated string name = 2;
          for (int i = 0, n = this_._internal_name_size(); i < n; ++i) {
            const auto& s = this_._internal_name().Get(i);
            ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
                s.data(), static_cast<int>(s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "kevin.JointState.name");
            target = stream->WriteString(2, s, target);
          }

          // repeated double position = 3;
          if (this_._internal_position_size() > 0) {
            target = stream->WriteFixedPacked(3, this_._internal_position(), target);
          }

          // repeated double velocity = 4;
          if (this_._internal_velocity_size() > 0) {
            target = stream->WriteFixedPacked(4, this_._internal_velocity(), target);
          }

          // repeated double effort = 5;
          if (this_._internal_effort_size() > 0) {
            target = stream->WriteFixedPacked(5, this_._internal_effort(), target);
          }

          if (PROTOBUF_PREDICT_FALSE(this_._internal_metadata_.have_unknown_fields())) {
            target =
                ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
                    this_._internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
          }
          // @@protoc_insertion_point(serialize_to_array_end:kevin.JointState)
          return target;
        }

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::size_t JointState::ByteSizeLong(const MessageLite& base) {
          const JointState& this_ = static_cast<const JointState&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::size_t JointState::ByteSizeLong() const {
          const JointState& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(message_byte_size_start:kevin.JointState)
          ::size_t total_size = 0;

          ::uint32_t cached_has_bits = 0;
          // Prevent compiler warnings about cached_has_bits being unused
          (void)cached_has_bits;

          ::_pbi::Prefetch5LinesFrom7Lines(&this_);
           {
            // repeated string name = 2;
            {
              total_size +=
                  1 * ::google::protobuf::internal::FromIntSize(this_._internal_name().size());
              for (int i = 0, n = this_._internal_name().size(); i < n; ++i) {
                total_size += ::google::protobuf::internal::WireFormatLite::StringSize(
                    this_._internal_name().Get(i));
              }
            }
            // repeated double position = 3;
            {
              std::size_t data_size = std::size_t{8} *
                  ::_pbi::FromIntSize(this_._internal_position_size());
              std::size_t tag_size = data_size == 0
                  ? 0
                  : 1 + ::_pbi::WireFormatLite::Int32Size(
                                      static_cast<int32_t>(data_size));
              total_size += tag_size + data_size;
            }
            // repeated double velocity = 4;
            {
              std::size_t data_size = std::size_t{8} *
                  ::_pbi::FromIntSize(this_._internal_velocity_size());
              std::size_t tag_size = data_size == 0
                  ? 0
                  : 1 + ::_pbi::WireFormatLite::Int32Size(
                                      static_cast<int32_t>(data_size));
              total_size += tag_size + data_size;
            }
            // repeated double effort = 5;
            {
              std::size_t data_size = std::size_t{8} *
                  ::_pbi::FromIntSize(this_._internal_effort_size());
              std::size_t tag_size = data_size == 0
                  ? 0
                  : 1 + ::_pbi::WireFormatLite::Int32Size(
                                      static_cast<int32_t>(data_size));
              total_size += tag_size + data_size;
            }
          }
           {
            // .kevin.Header header = 1;
            cached_has_bits = this_._impl_._has_bits_[0];
            if (cached_has_bits & 0x00000001u) {
              total_size += 1 +
                            ::google::protobuf::internal::WireFormatLite::MessageSize(*this_._impl_.header_);
            }
          }
          return this_.MaybeComputeUnknownFieldsSize(total_size,
                                                     &this_._impl_._cached_size_);
        }

void JointState::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<JointState*>(&to_msg);
  auto& from = static_cast<const JointState&>(from_msg);
  ::google::protobuf::Arena* arena = _this->GetArena();
  // @@protoc_insertion_point(class_specific_merge_from_start:kevin.JointState)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_internal_mutable_name()->MergeFrom(from._internal_name());
  _this->_internal_mutable_position()->MergeFrom(from._internal_position());
  _this->_internal_mutable_velocity()->MergeFrom(from._internal_velocity());
  _this->_internal_mutable_effort()->MergeFrom(from._internal_effort());
  cached_has_bits = from._impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    ABSL_DCHECK(from._impl_.header_ != nullptr);
    if (_this->_impl_.header_ == nullptr) {
      _this->_impl_.header_ =
          ::google::protobuf::Message::CopyConstruct<::kevin::Header>(arena, *from._impl_.header_);
    } else {
      _this->_impl_.header_->MergeFrom(*from._impl_.header_);
    }
  }
  _this->_impl_._has_bits_[0] |= cached_has_bits;
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void JointState::CopyFrom(const JointState& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:kevin.JointState)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void JointState::InternalSwap(JointState* PROTOBUF_RESTRICT other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  _impl_.name_.InternalSwap(&other->_impl_.name_);
  _impl_.position_.InternalSwap(&other->_impl_.position_);
  _impl_.velocity_.InternalSwap(&other->_impl_.velocity_);
  _impl_.effort_.InternalSwap(&other->_impl_.effort_);
  swap(_impl_.header_, other->_impl_.header_);
}

::google::protobuf::Metadata JointState::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace kevin
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::std::false_type
    _static_init2_ PROTOBUF_UNUSED =
        (::_pbi::AddDescriptors(&descriptor_table_kinematic_5fmsgs_2eproto),
         ::std::false_type{});
#include "google/protobuf/port_undef.inc"
