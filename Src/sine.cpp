// This file is generated. Do not edit.
// Generated on: 16.06.2020 11:51:10

#include <cassert>

#include "tensorflow/lite/c/builtin_op_data.h"
#include "tensorflow/lite/c/common.h"
#include "tensorflow/lite/micro/kernels/micro_ops.h"

namespace {

constexpr int kTensorArenaSize = 188;
uint8_t g_tensor_arena[kTensorArenaSize] __attribute__((aligned(16)));
template <int SZ, class T> struct TfArray {
  int sz; T elem[SZ];
};
enum used_operators_e {
  OP_FULLY_CONNECTED,  OP_LAST
};
struct TensorInfo_t { // subset of TfLiteTensor used for initialization from constant memory
  TfLiteType type;
  void* data;
  TfLiteIntArray* dims;
  // TfLiteQuantizationParams params;
  // TfLiteAllocationType allocation_type;
  size_t bytes;
  const char* name;
  TfLiteQuantization quantization;
};
struct NodeInfo_t { // subset of TfLiteNode used for initialization from constant memory
  struct TfLiteIntArray* inputs;
  struct TfLiteIntArray* outputs;
  void* builtin_data;
  used_operators_e used_op_index;
};

TfLiteContext g_ctx{};
TfLiteTensor g_tensors[10];
TfLiteRegistration *g_registrations[OP_LAST];
TfLiteNode g_nodes[3];

const TfArray<2, int> sine_tensor_dimension0 = { 2, { 1,1 } };
const float sine_tensor_data1[16] = { -0.056424889713525772, 0.0045356438495218754, 0, 0, -0.99112975597381592, 0.27034229040145874, 0, 0, -0.012637975625693798, -0.50121492147445679, 0, 0.61428004503250122, 0, -0.47242698073387146, 0.30524945259094238, 0, };
const TfArray<1, int> sine_tensor_dimension1 = { 1, { 16 } };
const float sine_tensor_data2[16] = { 0.43657481670379639, 0.076224051415920258, 0.15995869040489197, -0.19898606836795807, -0.5523914098739624, 0.52518904209136963, -0.3245689868927002, -0.0028310122434049845, -0.12306972593069077, -0.35056635737419128, -0.0031616361811757088, 0, 0.074008174240589142, 0.26824420690536499, -0.38956582546234131, -0.16231352090835571, };
const TfArray<1, int> sine_tensor_dimension2 = { 1, { 16 } };
const float sine_tensor_data3[1] = { -0.31196010112762451, };
const TfArray<1, int> sine_tensor_dimension3 = { 1, { 1 } };
const float sine_tensor_data4[16*1] = { 
  0.21873408555984497, 
  0.50932663679122925, 
  -0.5329517126083374, 
  -0.25533941388130188, 
  0.51144564151763916, 
  0.15760661661624908, 
  -0.57298153638839722, 
  -0.56859731674194336, 
  0.2698809802532196, 
  0.21719914674758911, 
  -0.35489559173583984, 
  -0.073797732591629028, 
  -0.49090650677680969, 
  0.16342359781265259, 
  0.069389566779136658, 
  -0.51110363006591797, 
};
const TfArray<2, int> sine_tensor_dimension4 = { 2, { 16,1 } };
const float sine_tensor_data5[16*16] = { 
  0.26381683349609375, -0.29852423071861267, 0.041821509599685669, -0.41997483372688293, -0.62821882963180542, 0.39483839273452759, -0.26914465427398682, -0.04637029767036438, 0.31066024303436279, -0.73338252305984497, -0.21672067046165466, 0.58971309661865234, 0.19084689021110535, -0.76059997081756592, 0.4783596396446228, -0.027467161417007446, 
  0.46797081828117371, 0.31744173169136047, 0.26579508185386658, -0.32047563791275024, -0.17376857995986938, -0.059257891029119492, 0.20566806197166443, -0.31811726093292236, 0.14757703244686127, 0.15008160471916199, -0.24522092938423157, -0.057315293699502945, -0.14062735438346863, -0.070421390235424042, -0.19951663911342621, -0.069129288196563721, 
  0.33985269069671631, -0.88856220245361328, 0.22414848208427429, 0.077520579099655151, -0.083979785442352295, -0.241567462682724, 0.054453641176223755, -0.11053887009620667, -0.39612531661987305, 0.43001297116279602, -0.044407635927200317, 0.47549459338188171, -0.22482889890670776, -0.35387858748435974, -0.13766485452651978, 0.29580345749855042, 
  -0.10118471086025238, 0.16986542940139771, 0.15006271004676819, -0.32151970267295837, 0.093038834631443024, -0.24503998458385468, -0.10203978419303894, -0.13433095812797546, 0.26668816804885864, -0.59187763929367065, -0.14425110816955566, 0.16433624923229218, 0.27570769190788269, -0.27218747138977051, -0.17668627202510834, -0.174968421459198, 
  0.37357401847839355, -0.36202022433280945, -0.10964152216911316, -0.42105895280838013, 0.60240828990936279, -0.33578592538833618, 0.22997602820396423, 0.17817750573158264, 0.37403702735900879, 0.54102087020874023, 0.3054143488407135, -0.6699908971786499, 0.31453624367713928, 0.0082072047516703606, -0.36841034889221191, 0.059751331806182861, 
  -0.59179025888442993, -0.89128947257995605, 0.266664057970047, -0.21946649253368378, -0.93636071681976318, -0.23512442409992218, -0.31696999073028564, -0.0085700154304504395, -0.00081960204988718033, -0.097417689859867096, -0.4193955659866333, 0.67625695466995239, 0.074338346719741821, 0.15587195754051208, 0.0047992928884923458, -0.34978634119033813, 
  -0.14969255030155182, 0.27412670850753784, 0.12340244650840759, -0.39365845918655396, -0.32431080937385559, 0.22225873172283173, -0.2492053210735321, -0.18743899464607239, 0.26498422026634216, -0.27287966012954712, 0.22582659125328064, -0.16922593116760254, 0.12865594029426575, 0.25383535027503967, -0.46519219875335693, -0.19474609196186066, 
  0.34090873599052429, -0.060675550252199173, 0.2212422788143158, -0.10907235741615295, 0.036923099309206009, 0.0082372771576046944, -0.15134328603744507, -0.036975711584091187, -0.1401517391204834, -0.41043883562088013, -0.3836788535118103, -0.37432539463043213, 0.38041034340858459, -0.35390698909759521, 0.082510769367218018, -0.37075680494308472, 
  0.088540136814117432, -0.30316981673240662, 0.2686488926410675, -0.34572359919548035, 0.16624954342842102, -0.4215659499168396, 0.0083175003528594971, 0.40375003218650818, -0.43887639045715332, -0.35154521465301514, -0.34383982419967651, 0.28413659334182739, -0.25348752737045288, 0.37752172350883484, 0.19821403920650482, 0.38296112418174744, 
  0.33097708225250244, -0.18591861426830292, -0.034565001726150513, 0.38510230183601379, -0.14078198373317719, 0.25161170959472656, 0.43007370829582214, -0.24869036674499512, 0.2158547043800354, -0.081452019512653351, -0.39846587181091309, -0.2124689519405365, 0.3179955780506134, 0.33104294538497925, 0.010678801685571671, 0.090628951787948608, 
  -0.41407424211502075, 0.29206135869026184, -0.091020137071609497, 0.077523916959762573, -0.17045143246650696, -0.29820281267166138, -0.13297614455223083, 0.017707228660583496, -0.084342151880264282, -0.16537100076675415, -0.11420723795890808, -0.2516358494758606, 0.25782385468482971, -0.25887304544448853, -0.21367885172367096, 0.057335942983627319, 
  -0.24751850962638855, -0.066706180572509766, -0.22400867938995361, -0.1420687735080719, -0.32700702548027039, -0.24980233609676361, -0.038889229297637939, 0.17512795329093933, 0.092300146818161011, -0.40698394179344177, -0.027647823095321655, -0.049985915422439575, 0.019776731729507446, -0.20401802659034729, 0.073563247919082642, -0.36362066864967346, 
  0.47297286987304688, 0.32181897759437561, -0.052533000707626343, 0.38433149456977844, -0.32904741168022156, 0.29427221417427063, -0.016770243644714355, 0.38996091485023499, -0.12657912075519562, 0.22261540591716766, -0.29916501045227051, 0.49557465314865112, -0.35335457324981689, -0.4769890308380127, -0.33366149663925171, 0.13865020871162415, 
  -0.23836065828800201, -0.035174418240785599, -0.26224586367607117, 0.2592988908290863, 0.21223606169223785, 0.1700962632894516, 0.081325620412826538, -0.28609979152679443, 0.48507747054100037, 0.22586469352245331, -0.16505682468414307, 0.87048661708831787, -0.3029140830039978, -0.58282053470611572, 0.33586680889129639, -0.0075096487998962402, 
  0.28853428363800049, -0.16245561838150024, -0.024419784545898438, 0.42412307858467102, 0.47034010291099548, 0.29448619484901428, 0.42480483651161194, 0.26865532994270325, -0.19419729709625244, 0.41530653834342957, -0.23053364455699921, -0.78353309631347656, 0.35473868250846863, 0.1125231608748436, 0.25421541929244995, 0.36740180850028992, 
  -0.091501437127590179, -0.43969565629959106, 0.4297964870929718, -0.25107660889625549, -0.40366646647453308, 0.20286476612091064, -0.26905947923660278, 0.17987349629402161, -0.093267202377319336, 0.43034431338310242, 0.31749776005744934, 0.056979116052389145, 0.4119020402431488, -0.21071365475654602, 0.21535122394561768, 0.090745836496353149, 
};
const TfArray<2, int> sine_tensor_dimension5 = { 2, { 16,16 } };
const float sine_tensor_data6[1*16] = { 
  1.5859265327453613, -0.3683130145072937, -0.76490277051925659, 0.0028504382353276014, 1.9055521488189697, -0.94064563512802124, 0.0014172254595905542, -0.02342616580426693, 0.47653332352638245, -0.0010237598326057196, -0.50726932287216187, -0.075169861316680908, -0.19486603140830994, -0.24001218378543854, 0.51395910978317261, 0.21489492058753967, 
};
const TfArray<2, int> sine_tensor_dimension6 = { 2, { 1,16 } };
const TfArray<2, int> sine_tensor_dimension7 = { 2, { 1,16 } };
const TfArray<2, int> sine_tensor_dimension8 = { 2, { 1,16 } };
const TfArray<2, int> sine_tensor_dimension9 = { 2, { 1,1 } };
const TfLiteFullyConnectedParams sine_opdata0 = { kTfLiteActRelu, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> sine_inputs0 = { 3, { 0,4,1 } };
const TfArray<1, int> sine_outputs0 = { 1, { 7 } };
const TfLiteFullyConnectedParams sine_opdata1 = { kTfLiteActRelu, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> sine_inputs1 = { 3, { 7,5,2 } };
const TfArray<1, int> sine_outputs1 = { 1, { 8 } };
const TfLiteFullyConnectedParams sine_opdata2 = { kTfLiteActNone, kTfLiteFullyConnectedWeightsFormatDefault, false, false };
const TfArray<3, int> sine_inputs2 = { 3, { 8,6,3 } };
const TfArray<1, int> sine_outputs2 = { 1, { 9 } };
const TensorInfo_t tensors[] = {
  { kTfLiteFloat32, g_tensor_arena + 0, (TfLiteIntArray*)&sine_tensor_dimension0, 4, "NO-NAME", {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteFloat32, (void*)sine_tensor_data1, (TfLiteIntArray*)&sine_tensor_dimension1, 64, "NO-NAME", {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteFloat32, (void*)sine_tensor_data2, (TfLiteIntArray*)&sine_tensor_dimension2, 64, "NO-NAME", {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteFloat32, (void*)sine_tensor_data3, (TfLiteIntArray*)&sine_tensor_dimension3, 4, "NO-NAME", {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteFloat32, (void*)sine_tensor_data4, (TfLiteIntArray*)&sine_tensor_dimension4, 64, "NO-NAME", {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteFloat32, (void*)sine_tensor_data5, (TfLiteIntArray*)&sine_tensor_dimension5, 1024, "NO-NAME", {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteFloat32, (void*)sine_tensor_data6, (TfLiteIntArray*)&sine_tensor_dimension6, 64, "NO-NAME", {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteFloat32, g_tensor_arena + 64, (TfLiteIntArray*)&sine_tensor_dimension7, 64, "NO-NAME", {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteFloat32, g_tensor_arena + 0, (TfLiteIntArray*)&sine_tensor_dimension8, 64, "NO-NAME", {kTfLiteNoQuantization, nullptr}, },
  { kTfLiteFloat32, g_tensor_arena + 64, (TfLiteIntArray*)&sine_tensor_dimension9, 4, "NO-NAME", {kTfLiteNoQuantization, nullptr}, },
};const NodeInfo_t nodes[] = {
  { (TfLiteIntArray*)&sine_inputs0, (TfLiteIntArray*)&sine_outputs0, const_cast<void*>(static_cast<const void*>(&sine_opdata0)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&sine_inputs1, (TfLiteIntArray*)&sine_outputs1, const_cast<void*>(static_cast<const void*>(&sine_opdata1)), OP_FULLY_CONNECTED, },
  { (TfLiteIntArray*)&sine_inputs2, (TfLiteIntArray*)&sine_outputs2, const_cast<void*>(static_cast<const void*>(&sine_opdata2)), OP_FULLY_CONNECTED, },
};
static TfLiteStatus AllocatePersistentBuffer(struct TfLiteContext* ctx,
                                                 size_t bytes, void** ptr) {
  static uint8_t *AllocPtr = g_tensor_arena + sizeof(g_tensor_arena);

  AllocPtr -= bytes;
  *ptr = AllocPtr;
  return kTfLiteOk;
}
} // namespace

TfLiteStatus sine_init() {
  g_ctx.AllocatePersistentBuffer = &AllocatePersistentBuffer;
  g_ctx.tensors = g_tensors;
  g_ctx.tensors_size = 10;
  for(size_t i = 0; i < 10; ++i) {
    g_tensors[i].data.data = tensors[i].data;
    g_tensors[i].type = tensors[i].type;
    g_tensors[i].is_variable = false;
    g_tensors[i].allocation_type = (g_tensor_arena <= tensors[i].data && tensors[i].data < g_tensor_arena + kTensorArenaSize) ? kTfLiteArenaRw : kTfLiteMmapRo;
    g_tensors[i].bytes = tensors[i].bytes;
    g_tensors[i].dims = tensors[i].dims;
    g_tensors[i].quantization = tensors[i].quantization;
    if (tensors[i].quantization.type == kTfLiteAffineQuantization) {
      TfLiteAffineQuantization const* quant = ((TfLiteAffineQuantization const*)(tensors[i].quantization.params));
      g_tensors[i].params.scale = quant->scale->data[0];
      g_tensors[i].params.zero_point = quant->zero_point->data[0];
    }
  }
  g_registrations[OP_FULLY_CONNECTED] = tflite::ops::micro::Register_FULLY_CONNECTED();

  for(size_t i = 0; i < 3; ++i) {
    g_nodes[i].inputs = nodes[i].inputs;
    g_nodes[i].outputs = nodes[i].outputs;
    g_nodes[i].temporaries = nullptr;
    g_nodes[i].builtin_data = nodes[i].builtin_data;
    g_nodes[i].custom_initial_data = nullptr;
    g_nodes[i].custom_initial_data_size = 0;
    g_nodes[i].delegate = nullptr;
    if (g_registrations[nodes[i].used_op_index]->init) {
      g_nodes[i].user_data = g_registrations[nodes[i].used_op_index]->init(&g_ctx, (const char*)g_nodes[i].builtin_data, 0);
    }
  }
  for(size_t i = 0; i < 3; ++i) {
    if (g_registrations[nodes[i].used_op_index]->prepare) {
      TfLiteStatus status = g_registrations[nodes[i].used_op_index]->prepare(&g_ctx, &g_nodes[i]);
      if (status != kTfLiteOk) {
        return status;
      }
    }
  }
  return kTfLiteOk;
}

static const int inTensorIndices[] = {
  0, 
};
void *sine_input_ptr(int index) {
  return g_ctx.tensors[inTensorIndices[index]].data.data;
}
size_t sine_input_size(int index) {
  return g_ctx.tensors[inTensorIndices[index]].bytes;
}
TfLiteTensor* sine_input(int index) {
  return &g_ctx.tensors[inTensorIndices[index]];
}

static const int outTensorIndices[] = {
  9, 
};
const void *sine_output_ptr(int index) {
  return g_ctx.tensors[outTensorIndices[index]].data.data;
}
size_t sine_output_size(int index) {
  return g_ctx.tensors[outTensorIndices[index]].bytes;
}
TfLiteTensor* sine_output(int index) {
  return &g_ctx.tensors[outTensorIndices[index]];
}

TfLiteStatus sine_invoke() {
  for(size_t i = 0; i < 3; ++i) {
    TfLiteStatus status = g_registrations[nodes[i].used_op_index]->invoke(&g_ctx, &g_nodes[i]);
    if (status != kTfLiteOk) {
      return status;
    }
  }
  return kTfLiteOk;
}
