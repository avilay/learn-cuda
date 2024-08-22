# CUDA Running Notes

## CUDA Device Properites

* `name[256]`

Memory related -

* `totalGlobalMem`: Global memory in bytes.

* `totalConstMem`: Constant memory in bytes.

* `sharedMemPerBlock`: Shared memory in bytes.

* `reservedSharedMemPerBlock`: Shared memory reserved by the CUDA driver per block in bytes.

* `regsPerBlock`: Maximum number of 32 bit registers in a block.

* `regsPerMultiprocessor`: Maximum number of 32 bit registers on the SM; this number is shared by all thread blocks simultaneously resident on the SM.

* `unifiedAddressing`: Is `1` if the device shares a unified address space with the host, `0` otherwise.

Threads related -

* `warpSize`: Warp size in threads. Product of blockDims should be a multiple of this number. This is how the block will be broken up on the SM, with each warp getting one processing block on the SM.
* `maxThreadsPerBlock`: Product of blockDims should be less than this.
* `maxThreadsDim[3]`: Actually the max blockDim in each of the 3 axes.
* `maxGridSize[3]`: Max gridDim in each of the 3 axes.
* `maxBlocksPerMultiProcessor`: Maximum number of thread blocks that can reside on the SM.

Hardware related -

* `clockRate`: KHz. This along with the number of SMs on the device give a good indication of the throughput capability.
* `multiProcessorCount`: Total number of SMs on the device. This tells me how many block  will be executing simultaneously.
* `integrated`: Is `1` if hte device is an integrated (motherboard) GPU and `0` if it is a discrete (card) component.
* `gpuDirectRDMASupported`: Is `1` if the device supports GPUDirect RDMA APIs, `0` otherwise.

