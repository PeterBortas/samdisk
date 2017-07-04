#ifndef FLUXTRACKBUFFER_H
#define FLUXTRACKBUFFER_H

#include "TrackBuffer.h"

class FluxTrackBuffer final : public TrackBuffer
{
public:
	FluxTrackBuffer (const CylHead &cylhead, DataRate datarate, Encoding encoding);

	void addBit (bool one) override;
	void addWeakBlock (int length);

	std::vector<uint32_t> &buffer ();

	static const int PRECOMP_NS{240};

private:
	CylHead m_cylhead{};
	std::vector<uint32_t> m_flux_times{};
	uint32_t m_flux_time{0};
	uint32_t m_bitcell_ns{0};
	bool m_last_bit{false};
	bool m_curr_bit{false};
};

#endif // FLUXTRACKBUFFER_H
