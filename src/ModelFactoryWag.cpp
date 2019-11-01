#include <iostream>
#include <sstream>
#include <cmath>
#include "ModelFactoryWag.h"
#include "debug.h"
#include <Eigen/Dense>

/*
 * The following model is described in:
 *
 * Whelan, S. and N. Goldman.  2001.  A general empirical model of
 *   protein evolution derived from multiple protein families using
 *   a maximum likelihood approach.  Molecular Biology and
 *   Evolution 18:691-699.
 */

ModelFactoryWag::ModelFactoryWag() {
   static double data[] = {
      -1.1171504619932122,
      0.020811755364152758,
      0.044243570856856054,
      0.096448866105925415,
      0.0084902433661125289,
      0.12378448654087996,
      0.0081270208878559281,
      0.009834136296328214,
      0.058997790771645749,
      0.036002402311430023,
      0.018288408561734703,
      0.02091646492897313,
      0.06909219016990284,
      0.035023440072619628,
      0.025454595840539756,
      0.24593305444632624,
      0.13582258698576632,
      0.14925914117823413,
      0.0017081063339924702,
      0.0089122009739363902,
      0.09337566488726258,
      -0.48735678471299987,
      0.0018137458487727548,
      0.0013010558101486048,
      0.016054075957414982,
      0.026795332617198755,
      0.0063838937022131469,
      0.0086540501139255738,
      0.0048196019290262168,
      0.034769373300962532,
      0.0079925308585637646,
      0.010882101766015943,
      0.0052545702084376977,
      0.0038091023739344775,
      0.024375626041997372,
      0.10270296382210568,
      0.032848279420825119,
      0.074565209415883071,
      0.010826476880450273,
      0.020133129757861336,
      0.067187674871823186,
      0.00061389044981838238,
      -0.98966441536441285,
      0.37621425350258103,
      0.0018848635523852695,
      0.075629532298549504,
      0.02386347322269541,
      0.0020059939127333166,
      0.03123852834516181,
      0.0076729274525969855,
      0.0021236754746682945,
      0.22274143080813358,
      0.020363548821379918,
      0.023774939454313731,
      0.0067979712234596586,
      0.078195678293039514,
      0.024004068574004306,
      0.011334635057345827,
      0.0019592500388321788,
      0.012058080010890794,
      0.14390838834592964,
      0.00043267311938716081,
      0.36964495904125094,
      -1.2368934668087197,
      0.0032725234745020633,
      0.049603702457457197,
      0.014616017092701385,
      0.006480046517551053,
      0.16824621981866719,
      0.01395734915187447,
      0.0064500752768989304,
      0.038858706414055748,
      0.032772862551446978,
      0.2108299322406508,
      0.020266772447325755,
      0.051432394622132727,
      0.052684712618083947,
      0.043805107374840099,
      0.0023637312130930779,
      0.0072672930308706057,
      0.019137538172592547,
      0.0080654062841175427,
      0.0027977339093870702,
      0.0049437866239703957,
      -0.71366939588492062,
      0.0043626709564858809,
      0.01741975904264836,
      0.053890771882333009,
      0.0057832176471450652,
      0.19137554828812042,
      0.024370257825282026,
      0.0039450408595236366,
      0.0077540019810154624,
      0.0038516155118195399,
      0.004740037082039625,
      0.039831160750725306,
      0.011007590445858154,
      0.048355851555378575,
      0.023094833273476729,
      0.23894257379300127,
      0.12880430359000883,
      0.006214387233745699,
      0.051822233668509098,
      0.034593082679380639,
      0.0020139592649356503,
      -0.49761525561951497,
      0.0063951244648754917,
      0.0015488682009818385,
      0.024318600768069434,
      0.0055466128961693143,
      0.0035635435755705805,
      0.046175990227391286,
      0.011698435758008573,
      0.012722410177931553,
      0.026981859592163426,
      0.097899273202177978,
      0.014460929554222349,
      0.013932296652659167,
      0.0050878417150414523,
      0.0038355023976725678,
      0.028816589897839837,
      0.0050451241982043937,
      0.055719270621538024,
      0.03473371759928618,
      0.02740232560490672,
      0.021791948153594833,
      -0.99234225258798514,
      0.0070291426528543491,
      0.057967063532606992,
      0.04519013322762766,
      0.0082721083525253876,
      0.16230641491944089,
      0.033437728693410732,
      0.16552370162628208,
      0.098627900126383602,
      0.05400277768015297,
      0.030307613079223666,
      0.0088065430539097222,
      0.0039643231595561769,
      0.1433978264086409,
      0.017577488871883193,
      0.0034475852925690623,
      0.0023610804141307989,
      0.0077626454165362268,
      0.042733560762279403,
      0.0026605468925535386,
      0.0035433312609804909,
      -1.2331622305527732,
      0.021081441500183266,
      0.28690181987981167,
      0.087143275308723289,
      0.022737478339376341,
      0.0047994853519517473,
      0.0043911226117079386,
      0.0086289432832188095,
      0.023306362874084254,
      0.093371425074213504,
      0.58195149620257269,
      0.0032081139735154387,
      0.015555027242481784,
      0.082395132554773931,
      0.0015002097439770106,
      0.028728763397893715,
      0.15747881544690703,
      0.0035831865025700146,
      0.032639254915041813,
      0.022831576390313194,
      0.016471968474991893,
      -1.1245802668478262,
      0.023302963515626097,
      0.019123108774323837,
      0.12356741917339355,
      0.026747185941995901,
      0.15013547986991624,
      0.24696409577911316,
      0.070561866786918045,
      0.088813504107527752,
      0.022726116283883317,
      0.0020760800248878276,
      0.004933539163772027,
      0.036177342356300719,
      0.0077871232217091545,
      0.0050772299159732781,
      0.0093998113732181639,
      0.085315059149905656,
      0.0053563491921876901,
      0.012806710458584832,
      0.16129387421609057,
      0.016766813241371144,
      -0.72601098581606116,
      0.099353887344578479,
      0.0053959234893104962,
      0.01997259235272536,
      0.033515917804465736,
      0.022967150496594743,
      0.025152179535590194,
      0.020914825259635273,
      0.13395606314466135,
      0.010044978184633983,
      0.014757155078524417,
      0.081234210034769397,
      0.0079126575966905841,
      0.0062117183682259538,
      0.019201663128384644,
      0.048023879345703728,
      0.015211812571832966,
      0.010362583682928696,
      0.21655903957465289,
      0.060821304994642972,
      0.43918017885158284,
      -1.3220983568797877,
      0.0081319973691884317,
      0.0082287691422747097,
      0.059564649059998143,
      0.031527423674585539,
      0.036035340456187642,
      0.097082820118173999,
      0.15316099080180864,
      0.0077862399572001164,
      0.015861078150955967,
      0.046353984257128306,
      0.0053751002695841491,
      0.32505761650455267,
      0.057716254274126001,
      0.003878683628020037,
      0.098344674085883474,
      0.10144327400321662,
      0.028191648508194389,
      0.19608164916675005,
      0.011900340452653877,
      0.0040572611780193921,
      -1.4524376593937451,
      0.009369555142702591,
      0.059502203431769103,
      0.029320750454435728,
      0.28996007552301478,
      0.12999231578575596,
      0.014601876072234806,
      0.0010858137836867784,
      0.040204582872016614,
      0.13078902742207857,
      0.0022169431413185158,
      0.025383784727662669,
      0.041578397214965875,
      0.0065118191017258034,
      0.021281684021374817,
      0.017851220328765436,
      0.0050829567286240097,
      0.036253892282683803,
      0.037624575567129427,
      0.0035068257165935218,
      0.0080031791726338196,
      -0.60558947293884802,
      0.035978395624314735,
      0.031357917426935993,
      0.11770501220104758,
      0.050931405031840293,
      0.023429476018659235,
      0.0021047666329914376,
      0.0079981945775024869,
      0.082607242527298855,
      0.0020024282991892338,
      0.036926598399189506,
      0.33327490267579107,
      0.0040302902188977209,
      0.028837961877993194,
      0.11010532021918328,
      0.0057944774845155884,
      0.2535577290047426,
      0.078669295662045863,
      0.031628956608766204,
      0.06332768182470086,
      0.04482897064631923,
      -1.3797850559067513,
      0.14008609167987152,
      0.075066421144061674,
      0.054936330698325181,
      0.022417108246379415,
      0.0032572435644465684,
      0.0084300051250339805,
      0.050147325184542291,
      0.010703168209171219,
      0.00881904275992401,
      0.026759449532476155,
      0.0041428325100800207,
      0.051084516928838149,
      0.054798685899156638,
      0.0095108333749768688,
      0.34837708340408219,
      0.045028087809536432,
      0.013983213992957778,
      0.026065008251014737,
      0.032635211293564427,
      0.11700845956125466,
      -0.97431787320966901,
      0.089316980862838707,
      0.035501132858993492,
      0.018739071812501978,
      0.017573114159975568,
      0.014124654803783715,
      0.30646299797995774,
      0.028524571151954423,
      0.064165923996470961,
      0.042954523311649839,
      0.022020043569437511,
      0.11724017429716781,
      0.018978681207820165,
      0.01624856595287498,
      0.062960098193113226,
      0.031191164370380799,
      0.010109431302080344,
      0.16304240168574333,
      0.077484306111918838,
      0.039659526861732193,
      0.056495467821967349,
      -1.3922386813370859,
      0.28034095463008746,
      0.017317173522904194,
      0.0079075692112635966,
      0.029135106158560749,
      0.19284551385439858,
      0.010395016273684119,
      0.022443105979753939,
      0.050134094400380143,
      0.0069336812705580314,
      0.019731931467747009,
      0.012136069825174711,
      0.074170451195354939,
      0.090292305059179415,
      0.029551981322050933,
      0.031032508246950426,
      0.083283015317724488,
      0.038201538066871495,
      0.033070279589678175,
      0.025585752049584128,
      0.31942061980340081,
      -1.1549728569687172,
      0.10329261447244034,
      0.0016738484846308436,
      0.010778530289154598,
      0.18238093698443836,
      0.020307186205631763,
      0.0091202471000992793,
      0.035873542907671335,
      0.02621329463875267,
      0.016360518487294706,
      0.003034818737876322,
      0.3978365542424902,
      0.019883732933023836,
      0.16289047906552886,
      0.042133120466015292,
      0.0080509731850497823,
      0.01512372353135462,
      0.011613383529920727,
      0.011622646056163385,
      0.016980652357098343,
      0.088893546271174254,
      -1.0854873310057245,
      0.0055164196401093837,
      0.011651554666031114,
      0.010285742615371045,
      0.014530578574323315,
      0.0077691082511476888,
      0.0095395932216857972,
      0.061697795958746429,
      0.029443551039023484,
      0.0067325345239480899,
      0.010808114323080186,
      0.0089515662858602602,
      0.060195575133923568,
      0.010555662281350959,
      0.0029503756675665722,
      0.0066954897435857657,
      0.0083159459859549981,
      0.053714051664647038,
      0.038212249888550695,
      0.0070990355444036368,
      0.027185638732184908,
      -0.46669372198073328,
      0.09201111254537879,
      0.021886967096349855,
      0.011020134907066218,
      0.019500212053831595,
      0.011961463033889171,
      0.26033239880012149,
      0.0090522954031716403,
      0.099318916271309607,
      0.021372276347418857,
      0.0086754774700475018,
      0.036066008078553487,
      0.008769407920084623,
      0.044553045050416636,
      0.010376484180213984,
      0.0087774654345884693,
      0.017607467243253638,
      0.057419059721275326,
      0.018643292689078782,
      0.023417794279702316,
      0.037524952060332059,
      -0.72627511804070533};

   this->Q = Eigen::Map<Model<AA>::Subst>(data);

   Eigen::EigenSolver<Model<AA>::Subst> solver2(this->Q.transpose());
   Model<AA>::Freqs sigma2 = solver2.eigenvalues().real();
   Model<AA>::Subst V2 = solver2.eigenvectors().real();

   Model<AA>::Freqs::Index izero;
   sigma2.maxCoeff(&izero);
   assert(std::abs(sigma2(izero)) < 1e-8 && "Invalid Q-Matrix");

   this->freqs = V2.col(izero)/V2.col(izero).sum();

   // normalize rate
   this->Q.diagonal().setZero();
   this->Q.diagonal() = -this->Q.rowwise().sum().eval();
   this->Q /= -(this->freqs.transpose() * this->Q.diagonal())(0,0);

   Eigen::EigenSolver<Model<AA>::Subst> solver(this->Q);
   this->sigma = solver.eigenvalues().real();
   this->V = solver.eigenvectors().real();
   this->Vi = this->V.inverse();
}
