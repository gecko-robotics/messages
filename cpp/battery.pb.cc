// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: battery.proto
// Protobuf C++ Version: 5.29.3

#include "battery.pb.h"

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

inline constexpr Battery::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        cell_voltage_{},
        cell_temperature_{},
        location_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        serial_number_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        header_{nullptr},
        voltage_{0},
        temperature_{0},
        current_{0},
        charge_{0},
        capacity_{0},
        design_capacity_{0},
        percentage_{0},
        status_{static_cast< ::kevin::BatteryStatus >(0)},
        health_{static_cast< ::kevin::BatteryHealth >(0)},
        technology_{static_cast< ::kevin::BatteryTechnology >(0)},
        present_{false} {}

template <typename>
PROTOBUF_CONSTEXPR Battery::Battery(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(),
#endif  // PROTOBUF_CUSTOM_VTABLE
      _impl_(::_pbi::ConstantInitialized()) {
}
struct BatteryDefaultTypeInternal {
  PROTOBUF_CONSTEXPR BatteryDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~BatteryDefaultTypeInternal() {}
  union {
    Battery _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 BatteryDefaultTypeInternal _Battery_default_instance_;
}  // namespace kevin
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_battery_2eproto[3];
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_battery_2eproto = nullptr;
const ::uint32_t
    TableStruct_battery_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        PROTOBUF_FIELD_OFFSET(::kevin::Battery, _impl_._has_bits_),
        PROTOBUF_FIELD_OFFSET(::kevin::Battery, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::kevin::Battery, _impl_.header_),
        PROTOBUF_FIELD_OFFSET(::kevin::Battery, _impl_.voltage_),
        PROTOBUF_FIELD_OFFSET(::kevin::Battery, _impl_.temperature_),
        PROTOBUF_FIELD_OFFSET(::kevin::Battery, _impl_.current_),
        PROTOBUF_FIELD_OFFSET(::kevin::Battery, _impl_.charge_),
        PROTOBUF_FIELD_OFFSET(::kevin::Battery, _impl_.capacity_),
        PROTOBUF_FIELD_OFFSET(::kevin::Battery, _impl_.design_capacity_),
        PROTOBUF_FIELD_OFFSET(::kevin::Battery, _impl_.percentage_),
        PROTOBUF_FIELD_OFFSET(::kevin::Battery, _impl_.status_),
        PROTOBUF_FIELD_OFFSET(::kevin::Battery, _impl_.health_),
        PROTOBUF_FIELD_OFFSET(::kevin::Battery, _impl_.technology_),
        PROTOBUF_FIELD_OFFSET(::kevin::Battery, _impl_.present_),
        PROTOBUF_FIELD_OFFSET(::kevin::Battery, _impl_.cell_voltage_),
        PROTOBUF_FIELD_OFFSET(::kevin::Battery, _impl_.cell_temperature_),
        PROTOBUF_FIELD_OFFSET(::kevin::Battery, _impl_.location_),
        PROTOBUF_FIELD_OFFSET(::kevin::Battery, _impl_.serial_number_),
        0,
        ~0u,
        ~0u,
        ~0u,
        ~0u,
        ~0u,
        ~0u,
        ~0u,
        ~0u,
        ~0u,
        ~0u,
        ~0u,
        ~0u,
        ~0u,
        ~0u,
        ~0u,
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, 24, -1, sizeof(::kevin::Battery)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::kevin::_Battery_default_instance_._instance,
};
const char descriptor_table_protodef_battery_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\rbattery.proto\022\005kevin\032\014header.proto\"\222\003\n"
    "\007Battery\022\035\n\006header\030\001 \001(\0132\r.kevin.Header\022"
    "\017\n\007voltage\030\002 \001(\002\022\023\n\013temperature\030\003 \001(\002\022\017\n"
    "\007current\030\004 \001(\002\022\016\n\006charge\030\005 \001(\002\022\020\n\010capaci"
    "ty\030\006 \001(\002\022\027\n\017design_capacity\030\007 \001(\002\022\022\n\nper"
    "centage\030\010 \001(\002\022$\n\006status\030\t \001(\0162\024.kevin.Ba"
    "tteryStatus\022$\n\006health\030\n \001(\0162\024.kevin.Batt"
    "eryHealth\022,\n\ntechnology\030\013 \001(\0162\030.kevin.Ba"
    "tteryTechnology\022\017\n\007present\030\014 \001(\010\022\024\n\014cell"
    "_voltage\030\r \003(\002\022\030\n\020cell_temperature\030\016 \003(\002"
    "\022\020\n\010location\030\017 \001(\t\022\025\n\rserial_number\030\020 \001("
    "\t*\242\001\n\rBatteryStatus\022\032\n\026BATTERY_STATUS_UN"
    "KNOWN\020\000\022\033\n\027BATTERY_STATUS_CHARGING\020\001\022\036\n\032"
    "BATTERY_STATUS_DISCHARGING\020\002\022\037\n\033BATTERY_"
    "STATUS_NOT_CHARGING\020\003\022\027\n\023BATTERY_STATUS_"
    "FULL\020\004*\250\002\n\rBatteryHealth\022\032\n\026BATTERY_HEAL"
    "TH_UNKNOWN\020\000\022\027\n\023BATTERY_HEALTH_GOOD\020\001\022\033\n"
    "\027BATTERY_HEALTH_OVERHEAT\020\002\022\027\n\023BATTERY_HE"
    "ALTH_DEAD\020\003\022\036\n\032BATTERY_HEALTH_OVERVOLTAG"
    "E\020\004\022!\n\035BATTERY_HEALTH_UNSPEC_FAILURE\020\005\022\027"
    "\n\023BATTERY_HEALTH_COLD\020\006\022(\n$BATTERY_HEALT"
    "H_WATCHDOG_TIMER_EXPIRE\020\007\022&\n\"BATTERY_HEA"
    "LTH_SAFETY_TIMER_EXPIRE\020\010*\236\002\n\021BatteryTec"
    "hnology\022\036\n\032BATTERY_TECHNOLOGY_UNKNOWN\020\000\022"
    "\033\n\027BATTERY_TECHNOLOGY_NIMH\020\001\022\033\n\027BATTERY_"
    "TECHNOLOGY_LION\020\002\022\033\n\027BATTERY_TECHNOLOGY_"
    "LIPO\020\003\022\033\n\027BATTERY_TECHNOLOGY_LIFE\020\004\022\033\n\027B"
    "ATTERY_TECHNOLOGY_NICD\020\005\022\033\n\027BATTERY_TECH"
    "NOLOGY_LIMN\020\006\022\036\n\032BATTERY_TECHNOLOGY_TERN"
    "ARY\020\007\022\033\n\027BATTERY_TECHNOLOGY_VRLA\020\010b\006prot"
    "o3"
};
static const ::_pbi::DescriptorTable* const descriptor_table_battery_2eproto_deps[1] =
    {
        &::descriptor_table_header_2eproto,
};
static ::absl::once_flag descriptor_table_battery_2eproto_once;
PROTOBUF_CONSTINIT const ::_pbi::DescriptorTable descriptor_table_battery_2eproto = {
    false,
    false,
    1202,
    descriptor_table_protodef_battery_2eproto,
    "battery.proto",
    &descriptor_table_battery_2eproto_once,
    descriptor_table_battery_2eproto_deps,
    1,
    1,
    schemas,
    file_default_instances,
    TableStruct_battery_2eproto::offsets,
    file_level_enum_descriptors_battery_2eproto,
    file_level_service_descriptors_battery_2eproto,
};
namespace kevin {
const ::google::protobuf::EnumDescriptor* BatteryStatus_descriptor() {
  ::google::protobuf::internal::AssignDescriptors(&descriptor_table_battery_2eproto);
  return file_level_enum_descriptors_battery_2eproto[0];
}
PROTOBUF_CONSTINIT const uint32_t BatteryStatus_internal_data_[] = {
    327680u, 0u, };
bool BatteryStatus_IsValid(int value) {
  return 0 <= value && value <= 4;
}
const ::google::protobuf::EnumDescriptor* BatteryHealth_descriptor() {
  ::google::protobuf::internal::AssignDescriptors(&descriptor_table_battery_2eproto);
  return file_level_enum_descriptors_battery_2eproto[1];
}
PROTOBUF_CONSTINIT const uint32_t BatteryHealth_internal_data_[] = {
    589824u, 0u, };
bool BatteryHealth_IsValid(int value) {
  return 0 <= value && value <= 8;
}
const ::google::protobuf::EnumDescriptor* BatteryTechnology_descriptor() {
  ::google::protobuf::internal::AssignDescriptors(&descriptor_table_battery_2eproto);
  return file_level_enum_descriptors_battery_2eproto[2];
}
PROTOBUF_CONSTINIT const uint32_t BatteryTechnology_internal_data_[] = {
    589824u, 0u, };
bool BatteryTechnology_IsValid(int value) {
  return 0 <= value && value <= 8;
}
// ===================================================================

class Battery::_Internal {
 public:
  using HasBits =
      decltype(std::declval<Battery>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
      8 * PROTOBUF_FIELD_OFFSET(Battery, _impl_._has_bits_);
};

void Battery::clear_header() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  if (_impl_.header_ != nullptr) _impl_.header_->Clear();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
Battery::Battery(::google::protobuf::Arena* arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:kevin.Battery)
}
inline PROTOBUF_NDEBUG_INLINE Battery::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::kevin::Battery& from_msg)
      : _has_bits_{from._has_bits_},
        _cached_size_{0},
        cell_voltage_{visibility, arena, from.cell_voltage_},
        cell_temperature_{visibility, arena, from.cell_temperature_},
        location_(arena, from.location_),
        serial_number_(arena, from.serial_number_) {}

Battery::Battery(
    ::google::protobuf::Arena* arena,
    const Battery& from)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  Battery* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);
  ::uint32_t cached_has_bits = _impl_._has_bits_[0];
  _impl_.header_ = (cached_has_bits & 0x00000001u) ? ::google::protobuf::Message::CopyConstruct<::kevin::Header>(
                              arena, *from._impl_.header_)
                        : nullptr;
  ::memcpy(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, voltage_),
           reinterpret_cast<const char *>(&from._impl_) +
               offsetof(Impl_, voltage_),
           offsetof(Impl_, present_) -
               offsetof(Impl_, voltage_) +
               sizeof(Impl_::present_));

  // @@protoc_insertion_point(copy_constructor:kevin.Battery)
}
inline PROTOBUF_NDEBUG_INLINE Battery::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0},
        cell_voltage_{visibility, arena},
        cell_temperature_{visibility, arena},
        location_(arena),
        serial_number_(arena) {}

inline void Battery::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, header_),
           0,
           offsetof(Impl_, present_) -
               offsetof(Impl_, header_) +
               sizeof(Impl_::present_));
}
Battery::~Battery() {
  // @@protoc_insertion_point(destructor:kevin.Battery)
  SharedDtor(*this);
}
inline void Battery::SharedDtor(MessageLite& self) {
  Battery& this_ = static_cast<Battery&>(self);
  this_._internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  ABSL_DCHECK(this_.GetArena() == nullptr);
  this_._impl_.location_.Destroy();
  this_._impl_.serial_number_.Destroy();
  delete this_._impl_.header_;
  this_._impl_.~Impl_();
}

inline void* Battery::PlacementNew_(const void*, void* mem,
                                        ::google::protobuf::Arena* arena) {
  return ::new (mem) Battery(arena);
}
constexpr auto Battery::InternalNewImpl_() {
  constexpr auto arena_bits = ::google::protobuf::internal::EncodePlacementArenaOffsets({
      PROTOBUF_FIELD_OFFSET(Battery, _impl_.cell_voltage_) +
          decltype(Battery::_impl_.cell_voltage_)::
              InternalGetArenaOffset(
                  ::google::protobuf::Message::internal_visibility()),
      PROTOBUF_FIELD_OFFSET(Battery, _impl_.cell_temperature_) +
          decltype(Battery::_impl_.cell_temperature_)::
              InternalGetArenaOffset(
                  ::google::protobuf::Message::internal_visibility()),
  });
  if (arena_bits.has_value()) {
    return ::google::protobuf::internal::MessageCreator::CopyInit(
        sizeof(Battery), alignof(Battery), *arena_bits);
  } else {
    return ::google::protobuf::internal::MessageCreator(&Battery::PlacementNew_,
                                 sizeof(Battery),
                                 alignof(Battery));
  }
}
PROTOBUF_CONSTINIT
PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::google::protobuf::internal::ClassDataFull Battery::_class_data_ = {
    ::google::protobuf::internal::ClassData{
        &_Battery_default_instance_._instance,
        &_table_.header,
        nullptr,  // OnDemandRegisterArenaDtor
        nullptr,  // IsInitialized
        &Battery::MergeImpl,
        ::google::protobuf::Message::GetNewImpl<Battery>(),
#if defined(PROTOBUF_CUSTOM_VTABLE)
        &Battery::SharedDtor,
        ::google::protobuf::Message::GetClearImpl<Battery>(), &Battery::ByteSizeLong,
            &Battery::_InternalSerialize,
#endif  // PROTOBUF_CUSTOM_VTABLE
        PROTOBUF_FIELD_OFFSET(Battery, _impl_._cached_size_),
        false,
    },
    &Battery::kDescriptorMethods,
    &descriptor_table_battery_2eproto,
    nullptr,  // tracker
};
const ::google::protobuf::internal::ClassData* Battery::GetClassData() const {
  ::google::protobuf::internal::PrefetchToLocalCache(&_class_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_class_data_.tc_table);
  return _class_data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<4, 16, 1, 59, 2> Battery::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(Battery, _impl_._has_bits_),
    0, // no _extensions_
    16, 120,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294901760,  // skipmap
    offsetof(decltype(_table_), field_entries),
    16,  // num_field_entries
    1,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    _class_data_.base(),
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::kevin::Battery>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // string serial_number = 16;
    {::_pbi::TcParser::FastUS2,
     {386, 63, 0, PROTOBUF_FIELD_OFFSET(Battery, _impl_.serial_number_)}},
    // .kevin.Header header = 1;
    {::_pbi::TcParser::FastMtS1,
     {10, 0, 0, PROTOBUF_FIELD_OFFSET(Battery, _impl_.header_)}},
    // float voltage = 2;
    {::_pbi::TcParser::FastF32S1,
     {21, 63, 0, PROTOBUF_FIELD_OFFSET(Battery, _impl_.voltage_)}},
    // float temperature = 3;
    {::_pbi::TcParser::FastF32S1,
     {29, 63, 0, PROTOBUF_FIELD_OFFSET(Battery, _impl_.temperature_)}},
    // float current = 4;
    {::_pbi::TcParser::FastF32S1,
     {37, 63, 0, PROTOBUF_FIELD_OFFSET(Battery, _impl_.current_)}},
    // float charge = 5;
    {::_pbi::TcParser::FastF32S1,
     {45, 63, 0, PROTOBUF_FIELD_OFFSET(Battery, _impl_.charge_)}},
    // float capacity = 6;
    {::_pbi::TcParser::FastF32S1,
     {53, 63, 0, PROTOBUF_FIELD_OFFSET(Battery, _impl_.capacity_)}},
    // float design_capacity = 7;
    {::_pbi::TcParser::FastF32S1,
     {61, 63, 0, PROTOBUF_FIELD_OFFSET(Battery, _impl_.design_capacity_)}},
    // float percentage = 8;
    {::_pbi::TcParser::FastF32S1,
     {69, 63, 0, PROTOBUF_FIELD_OFFSET(Battery, _impl_.percentage_)}},
    // .kevin.BatteryStatus status = 9;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(Battery, _impl_.status_), 63>(),
     {72, 63, 0, PROTOBUF_FIELD_OFFSET(Battery, _impl_.status_)}},
    // .kevin.BatteryHealth health = 10;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(Battery, _impl_.health_), 63>(),
     {80, 63, 0, PROTOBUF_FIELD_OFFSET(Battery, _impl_.health_)}},
    // .kevin.BatteryTechnology technology = 11;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(Battery, _impl_.technology_), 63>(),
     {88, 63, 0, PROTOBUF_FIELD_OFFSET(Battery, _impl_.technology_)}},
    // bool present = 12;
    {::_pbi::TcParser::SingularVarintNoZag1<bool, offsetof(Battery, _impl_.present_), 63>(),
     {96, 63, 0, PROTOBUF_FIELD_OFFSET(Battery, _impl_.present_)}},
    // repeated float cell_voltage = 13;
    {::_pbi::TcParser::FastF32P1,
     {106, 63, 0, PROTOBUF_FIELD_OFFSET(Battery, _impl_.cell_voltage_)}},
    // repeated float cell_temperature = 14;
    {::_pbi::TcParser::FastF32P1,
     {114, 63, 0, PROTOBUF_FIELD_OFFSET(Battery, _impl_.cell_temperature_)}},
    // string location = 15;
    {::_pbi::TcParser::FastUS1,
     {122, 63, 0, PROTOBUF_FIELD_OFFSET(Battery, _impl_.location_)}},
  }}, {{
    65535, 65535
  }}, {{
    // .kevin.Header header = 1;
    {PROTOBUF_FIELD_OFFSET(Battery, _impl_.header_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kMessage | ::_fl::kTvTable)},
    // float voltage = 2;
    {PROTOBUF_FIELD_OFFSET(Battery, _impl_.voltage_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kFloat)},
    // float temperature = 3;
    {PROTOBUF_FIELD_OFFSET(Battery, _impl_.temperature_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kFloat)},
    // float current = 4;
    {PROTOBUF_FIELD_OFFSET(Battery, _impl_.current_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kFloat)},
    // float charge = 5;
    {PROTOBUF_FIELD_OFFSET(Battery, _impl_.charge_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kFloat)},
    // float capacity = 6;
    {PROTOBUF_FIELD_OFFSET(Battery, _impl_.capacity_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kFloat)},
    // float design_capacity = 7;
    {PROTOBUF_FIELD_OFFSET(Battery, _impl_.design_capacity_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kFloat)},
    // float percentage = 8;
    {PROTOBUF_FIELD_OFFSET(Battery, _impl_.percentage_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kFloat)},
    // .kevin.BatteryStatus status = 9;
    {PROTOBUF_FIELD_OFFSET(Battery, _impl_.status_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kOpenEnum)},
    // .kevin.BatteryHealth health = 10;
    {PROTOBUF_FIELD_OFFSET(Battery, _impl_.health_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kOpenEnum)},
    // .kevin.BatteryTechnology technology = 11;
    {PROTOBUF_FIELD_OFFSET(Battery, _impl_.technology_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kOpenEnum)},
    // bool present = 12;
    {PROTOBUF_FIELD_OFFSET(Battery, _impl_.present_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kBool)},
    // repeated float cell_voltage = 13;
    {PROTOBUF_FIELD_OFFSET(Battery, _impl_.cell_voltage_), -1, 0,
    (0 | ::_fl::kFcRepeated | ::_fl::kPackedFloat)},
    // repeated float cell_temperature = 14;
    {PROTOBUF_FIELD_OFFSET(Battery, _impl_.cell_temperature_), -1, 0,
    (0 | ::_fl::kFcRepeated | ::_fl::kPackedFloat)},
    // string location = 15;
    {PROTOBUF_FIELD_OFFSET(Battery, _impl_.location_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // string serial_number = 16;
    {PROTOBUF_FIELD_OFFSET(Battery, _impl_.serial_number_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }}, {{
    {::_pbi::TcParser::GetTable<::kevin::Header>()},
  }}, {{
    "\15\0\0\0\0\0\0\0\0\0\0\0\0\0\0\10\15\0\0\0\0\0\0\0"
    "kevin.Battery"
    "location"
    "serial_number"
  }},
};

PROTOBUF_NOINLINE void Battery::Clear() {
// @@protoc_insertion_point(message_clear_start:kevin.Battery)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.cell_voltage_.Clear();
  _impl_.cell_temperature_.Clear();
  _impl_.location_.ClearToEmpty();
  _impl_.serial_number_.ClearToEmpty();
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    ABSL_DCHECK(_impl_.header_ != nullptr);
    _impl_.header_->Clear();
  }
  ::memset(&_impl_.voltage_, 0, static_cast<::size_t>(
      reinterpret_cast<char*>(&_impl_.present_) -
      reinterpret_cast<char*>(&_impl_.voltage_)) + sizeof(_impl_.present_));
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::uint8_t* Battery::_InternalSerialize(
            const MessageLite& base, ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) {
          const Battery& this_ = static_cast<const Battery&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::uint8_t* Battery::_InternalSerialize(
            ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) const {
          const Battery& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(serialize_to_array_start:kevin.Battery)
          ::uint32_t cached_has_bits = 0;
          (void)cached_has_bits;

          cached_has_bits = this_._impl_._has_bits_[0];
          // .kevin.Header header = 1;
          if (cached_has_bits & 0x00000001u) {
            target = ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
                1, *this_._impl_.header_, this_._impl_.header_->GetCachedSize(), target,
                stream);
          }

          // float voltage = 2;
          if (::absl::bit_cast<::uint32_t>(this_._internal_voltage()) != 0) {
            target = stream->EnsureSpace(target);
            target = ::_pbi::WireFormatLite::WriteFloatToArray(
                2, this_._internal_voltage(), target);
          }

          // float temperature = 3;
          if (::absl::bit_cast<::uint32_t>(this_._internal_temperature()) != 0) {
            target = stream->EnsureSpace(target);
            target = ::_pbi::WireFormatLite::WriteFloatToArray(
                3, this_._internal_temperature(), target);
          }

          // float current = 4;
          if (::absl::bit_cast<::uint32_t>(this_._internal_current()) != 0) {
            target = stream->EnsureSpace(target);
            target = ::_pbi::WireFormatLite::WriteFloatToArray(
                4, this_._internal_current(), target);
          }

          // float charge = 5;
          if (::absl::bit_cast<::uint32_t>(this_._internal_charge()) != 0) {
            target = stream->EnsureSpace(target);
            target = ::_pbi::WireFormatLite::WriteFloatToArray(
                5, this_._internal_charge(), target);
          }

          // float capacity = 6;
          if (::absl::bit_cast<::uint32_t>(this_._internal_capacity()) != 0) {
            target = stream->EnsureSpace(target);
            target = ::_pbi::WireFormatLite::WriteFloatToArray(
                6, this_._internal_capacity(), target);
          }

          // float design_capacity = 7;
          if (::absl::bit_cast<::uint32_t>(this_._internal_design_capacity()) != 0) {
            target = stream->EnsureSpace(target);
            target = ::_pbi::WireFormatLite::WriteFloatToArray(
                7, this_._internal_design_capacity(), target);
          }

          // float percentage = 8;
          if (::absl::bit_cast<::uint32_t>(this_._internal_percentage()) != 0) {
            target = stream->EnsureSpace(target);
            target = ::_pbi::WireFormatLite::WriteFloatToArray(
                8, this_._internal_percentage(), target);
          }

          // .kevin.BatteryStatus status = 9;
          if (this_._internal_status() != 0) {
            target = stream->EnsureSpace(target);
            target = ::_pbi::WireFormatLite::WriteEnumToArray(
                9, this_._internal_status(), target);
          }

          // .kevin.BatteryHealth health = 10;
          if (this_._internal_health() != 0) {
            target = stream->EnsureSpace(target);
            target = ::_pbi::WireFormatLite::WriteEnumToArray(
                10, this_._internal_health(), target);
          }

          // .kevin.BatteryTechnology technology = 11;
          if (this_._internal_technology() != 0) {
            target = stream->EnsureSpace(target);
            target = ::_pbi::WireFormatLite::WriteEnumToArray(
                11, this_._internal_technology(), target);
          }

          // bool present = 12;
          if (this_._internal_present() != 0) {
            target = stream->EnsureSpace(target);
            target = ::_pbi::WireFormatLite::WriteBoolToArray(
                12, this_._internal_present(), target);
          }

          // repeated float cell_voltage = 13;
          if (this_._internal_cell_voltage_size() > 0) {
            target = stream->WriteFixedPacked(13, this_._internal_cell_voltage(), target);
          }

          // repeated float cell_temperature = 14;
          if (this_._internal_cell_temperature_size() > 0) {
            target = stream->WriteFixedPacked(14, this_._internal_cell_temperature(), target);
          }

          // string location = 15;
          if (!this_._internal_location().empty()) {
            const std::string& _s = this_._internal_location();
            ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
                _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "kevin.Battery.location");
            target = stream->WriteStringMaybeAliased(15, _s, target);
          }

          // string serial_number = 16;
          if (!this_._internal_serial_number().empty()) {
            const std::string& _s = this_._internal_serial_number();
            ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
                _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "kevin.Battery.serial_number");
            target = stream->WriteStringMaybeAliased(16, _s, target);
          }

          if (PROTOBUF_PREDICT_FALSE(this_._internal_metadata_.have_unknown_fields())) {
            target =
                ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
                    this_._internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
          }
          // @@protoc_insertion_point(serialize_to_array_end:kevin.Battery)
          return target;
        }

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::size_t Battery::ByteSizeLong(const MessageLite& base) {
          const Battery& this_ = static_cast<const Battery&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::size_t Battery::ByteSizeLong() const {
          const Battery& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(message_byte_size_start:kevin.Battery)
          ::size_t total_size = 0;

          ::uint32_t cached_has_bits = 0;
          // Prevent compiler warnings about cached_has_bits being unused
          (void)cached_has_bits;

          ::_pbi::Prefetch5LinesFrom7Lines(&this_);
           {
            // repeated float cell_voltage = 13;
            {
              std::size_t data_size = std::size_t{4} *
                  ::_pbi::FromIntSize(this_._internal_cell_voltage_size());
              std::size_t tag_size = data_size == 0
                  ? 0
                  : 1 + ::_pbi::WireFormatLite::Int32Size(
                                      static_cast<int32_t>(data_size));
              total_size += tag_size + data_size;
            }
            // repeated float cell_temperature = 14;
            {
              std::size_t data_size = std::size_t{4} *
                  ::_pbi::FromIntSize(this_._internal_cell_temperature_size());
              std::size_t tag_size = data_size == 0
                  ? 0
                  : 1 + ::_pbi::WireFormatLite::Int32Size(
                                      static_cast<int32_t>(data_size));
              total_size += tag_size + data_size;
            }
          }
           {
            // string location = 15;
            if (!this_._internal_location().empty()) {
              total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                              this_._internal_location());
            }
            // string serial_number = 16;
            if (!this_._internal_serial_number().empty()) {
              total_size += 2 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                              this_._internal_serial_number());
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
           {
            // float voltage = 2;
            if (::absl::bit_cast<::uint32_t>(this_._internal_voltage()) != 0) {
              total_size += 5;
            }
            // float temperature = 3;
            if (::absl::bit_cast<::uint32_t>(this_._internal_temperature()) != 0) {
              total_size += 5;
            }
            // float current = 4;
            if (::absl::bit_cast<::uint32_t>(this_._internal_current()) != 0) {
              total_size += 5;
            }
            // float charge = 5;
            if (::absl::bit_cast<::uint32_t>(this_._internal_charge()) != 0) {
              total_size += 5;
            }
            // float capacity = 6;
            if (::absl::bit_cast<::uint32_t>(this_._internal_capacity()) != 0) {
              total_size += 5;
            }
            // float design_capacity = 7;
            if (::absl::bit_cast<::uint32_t>(this_._internal_design_capacity()) != 0) {
              total_size += 5;
            }
            // float percentage = 8;
            if (::absl::bit_cast<::uint32_t>(this_._internal_percentage()) != 0) {
              total_size += 5;
            }
            // .kevin.BatteryStatus status = 9;
            if (this_._internal_status() != 0) {
              total_size += 1 +
                            ::_pbi::WireFormatLite::EnumSize(this_._internal_status());
            }
            // .kevin.BatteryHealth health = 10;
            if (this_._internal_health() != 0) {
              total_size += 1 +
                            ::_pbi::WireFormatLite::EnumSize(this_._internal_health());
            }
            // .kevin.BatteryTechnology technology = 11;
            if (this_._internal_technology() != 0) {
              total_size += 1 +
                            ::_pbi::WireFormatLite::EnumSize(this_._internal_technology());
            }
            // bool present = 12;
            if (this_._internal_present() != 0) {
              total_size += 2;
            }
          }
          return this_.MaybeComputeUnknownFieldsSize(total_size,
                                                     &this_._impl_._cached_size_);
        }

void Battery::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<Battery*>(&to_msg);
  auto& from = static_cast<const Battery&>(from_msg);
  ::google::protobuf::Arena* arena = _this->GetArena();
  // @@protoc_insertion_point(class_specific_merge_from_start:kevin.Battery)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_internal_mutable_cell_voltage()->MergeFrom(from._internal_cell_voltage());
  _this->_internal_mutable_cell_temperature()->MergeFrom(from._internal_cell_temperature());
  if (!from._internal_location().empty()) {
    _this->_internal_set_location(from._internal_location());
  }
  if (!from._internal_serial_number().empty()) {
    _this->_internal_set_serial_number(from._internal_serial_number());
  }
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
  if (::absl::bit_cast<::uint32_t>(from._internal_voltage()) != 0) {
    _this->_impl_.voltage_ = from._impl_.voltage_;
  }
  if (::absl::bit_cast<::uint32_t>(from._internal_temperature()) != 0) {
    _this->_impl_.temperature_ = from._impl_.temperature_;
  }
  if (::absl::bit_cast<::uint32_t>(from._internal_current()) != 0) {
    _this->_impl_.current_ = from._impl_.current_;
  }
  if (::absl::bit_cast<::uint32_t>(from._internal_charge()) != 0) {
    _this->_impl_.charge_ = from._impl_.charge_;
  }
  if (::absl::bit_cast<::uint32_t>(from._internal_capacity()) != 0) {
    _this->_impl_.capacity_ = from._impl_.capacity_;
  }
  if (::absl::bit_cast<::uint32_t>(from._internal_design_capacity()) != 0) {
    _this->_impl_.design_capacity_ = from._impl_.design_capacity_;
  }
  if (::absl::bit_cast<::uint32_t>(from._internal_percentage()) != 0) {
    _this->_impl_.percentage_ = from._impl_.percentage_;
  }
  if (from._internal_status() != 0) {
    _this->_impl_.status_ = from._impl_.status_;
  }
  if (from._internal_health() != 0) {
    _this->_impl_.health_ = from._impl_.health_;
  }
  if (from._internal_technology() != 0) {
    _this->_impl_.technology_ = from._impl_.technology_;
  }
  if (from._internal_present() != 0) {
    _this->_impl_.present_ = from._impl_.present_;
  }
  _this->_impl_._has_bits_[0] |= cached_has_bits;
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void Battery::CopyFrom(const Battery& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:kevin.Battery)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void Battery::InternalSwap(Battery* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  _impl_.cell_voltage_.InternalSwap(&other->_impl_.cell_voltage_);
  _impl_.cell_temperature_.InternalSwap(&other->_impl_.cell_temperature_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.location_, &other->_impl_.location_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.serial_number_, &other->_impl_.serial_number_, arena);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Battery, _impl_.present_)
      + sizeof(Battery::_impl_.present_)
      - PROTOBUF_FIELD_OFFSET(Battery, _impl_.header_)>(
          reinterpret_cast<char*>(&_impl_.header_),
          reinterpret_cast<char*>(&other->_impl_.header_));
}

::google::protobuf::Metadata Battery::GetMetadata() const {
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
        (::_pbi::AddDescriptors(&descriptor_table_battery_2eproto),
         ::std::false_type{});
#include "google/protobuf/port_undef.inc"
